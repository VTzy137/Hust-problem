int nearPoint[8][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}};

typedef pair<double, pair<int, int>> pairDistance;
double gDistance[1000][1000] = {};
path* astarRes;
path* aStar(){
    set<pairDistance> aStar;
    int xStart = start->x, yStart = start->y, xFinish = finish->x, yFinish = finish->y;
    // cout << xStart << " " << yStart << endl;
    aStar.insert(make_pair(0.0, make_pair(xStart, yStart)));
    // cout << "cc" << endl;
    while(aStar.empty() == false) {
        pairDistance newPoint = *aStar.begin();
        aStar.erase(aStar.begin());
        int x = newPoint.second.first, y = newPoint.second.second, past = x*1000+y;
    // cout << newPoint.second.first << " " << newPoint.second.second << endl;
        for(int i = 0; i < 8; ++i) {
            x += nearPoint[i][0];
            y += nearPoint[i][1];
            if(checkValidPoint(x, y)){
                graphStatus[x][y] = past;
                gDistance[x][y] = gDistance[x][y] + sqrt(abs(nearPoint[i][0]) + abs(nearPoint[i][1]));
                aStar.insert(make_pair(gDistance[x][y] + distanceToFinish(x, y), make_pair(x, y)));
                if(x == xFinish && y == yFinish) goto findSolution;
            }
            x -= nearPoint[i][0];
            y -= nearPoint[i][1];
        }
    }
    
    findSolution:
    path *res = new path(gDistance[xFinish][yFinish], 0, nullptr);
    point *p = new point((double) xFinish, (double) yFinish, nullptr);
    int stop = 100;
    while(--stop > 0){
        int tmp = graphStatus[xFinish][yFinish];
        xFinish = tmp / 1000;
        yFinish = tmp % 1000;
        p = new point((double) xFinish, (double) yFinish, p);
        if(xFinish == xStart && yFinish == yStart) break;
    }
    
    res->begin = p;
    astarRes = res;
    return res;
}

path *currPath, *gPath, *pPath[1000], *population[1000];
double w1, w2, w0, v[1000][1000] = {};
int numPopulations = 100, populationMax = 100, dim = 0;

path* makeCopyPath(path *p) {
    point *p1 = p->begin, *q1 = new point(p1->x, p1->y, nullptr);
    path *q = new path(q1);
    p1 = p1->next;
    while(p1 != nullptr) {
        q1->next = new point(p1->x, p1->y, nullptr);
        q1 = q1->next;
        p1 = p1->next;
    }
    pathFunc(q);
    return q;
}

void setPathFromAstar(){
    point *p = astarRes->begin;
    for(int i = 0; i <= populationMax; ++i) {
        point *q = p, *tmp = new point();
        population[i] = new path(tmp);
        while(q != nullptr) {
            tmp->next = new point(q->x, q->y, nullptr);
            tmp = tmp->next;
            q = q->next;
        }
        population[i]->begin = population[i]->begin->next;
        pathFunc(population[i]);
        pPath[i] = population[i];
    }
    // gPath = population[0];
    gPath = pPath[populationMax];
}

void updateBestPath(){
    for (int i = 0; i < numPopulations; i++) {
        if(compareTwoPath(population[i], pPath[i]) > 0) pPath[i] = makeCopyPath(population[i]);
        else population[i] = pPath[i];
        if(compareTwoPath(population[i], gPath) > 0){ 
            gPath = population[i];
            // cout << population[i]->distance << " " << population[i]->angle << endl;
        }
    }
}

void PSO(){
    updateBestPath();
    for(int i = 0; i < numPopulations; i++) {
        for(int j = 0; j < dim; ++j) {
            ;
        }   
    }
}

//
// path* mutation(path *p, double toiu){
//     point *tmp = p->begin, *offPoint = new point(tmp->x, tmp->y, nullptr);
//     path *offspring = new path(offPoint);
//     tmp = tmp->next;
//     while(tmp->next != nullptr) {
//         double x1 = (rand() % 100)/toiu, y1 = (rand() % 100)/toiu;
//         // cout << x1 << y1;
//         int i = 0;
//         for(i; i < 8; ++i){
//             if(checkValidPosition(tmp->x + x1*nearPoint[i][0], tmp->y + y1*nearPoint[i][1])){
//                 // cout << tmp->y << " " << tmp->x << endl;
//                 offPoint->next = new point(tmp->x + x1*nearPoint[i][0], tmp->y + y1*(double)nearPoint[i][1], nullptr);
//                 break;
//             }
//         }
//         if(i == 8) offPoint->next = tmp;
//         offPoint = offPoint->next;
//         tmp = tmp->next;
//     }
//     offPoint->next = new point(tmp->x, tmp->y, nullptr);
//     // offspring->begin = offspring->begin->next;
//     pathFunc(offspring);
//     return offspring;
// }

path* mutation(path *p, double toiu){
    point *tmp = p->begin, *offPoint = new point(tmp->x, tmp->y, nullptr);
    path *offspring = new path(offPoint);
    tmp = tmp->next;
    double x1 = (rand() % 200 - 100) / toiu, y1 = (rand() % 200 - 100) / toiu, stt = 0, posPoint = rand() % 30;
    while(tmp->next != nullptr) {
        double wei = max(0.5, abs(stt++ - posPoint));
        offPoint->next = new point(tmp->x + x1 / wei, tmp->y + y1 /wei, nullptr);
        if(checkValidPoint(offPoint) == false) return p;
        offPoint = offPoint->next;
        tmp = tmp->next;
    }
    offPoint->next = new point(tmp->x, tmp->y, nullptr);
    // offspring->begin = offspring->begin->next;
    pathFunc(offspring);
    return offspring;
}

path* combination1(path *p, path *q){
    if(q == nullptr) return nullptr;
    point *p1 = p->begin, *q1 = q->begin->next, *tmp1 = new point(p1->x, p1->y, nullptr);
    p1 = p1->next;
    path *tmp = new path(tmp1);
    while(p1->next != nullptr) {
        tmp1->next = new point((p1->x + q1->x)/2, (p1->y + q1->y)/2, nullptr);
        tmp1 = tmp1->next;
        p1 = p1->next;
        q1 = q1->next;
    }
    tmp1->next = new point(p1->x, p1->y, nullptr);
    // tmp->begin = tmp->begin->next;
    pathFunc(tmp);
    return tmp;
}

int chooseCombine = 52465, modCombine = 9383761; 
path* combination2(path *p, path *q){
    if(q == nullptr) return nullptr;
    point *p1 = p->begin, *q1 = q->begin->next, *tmp1 = new point(p1->x, p1->y, nullptr);
    p1 = p1->next;
    path *tmp = new path(tmp1);
    while(p1->next != nullptr) {
        chooseCombine = (chooseCombine * 6) % modCombine;
        if((chooseCombine & 1) == 1) tmp1->next = new point(p1->x, p1->y, nullptr);
        else tmp1->next = new point(q1->x, q1->y, nullptr);
        tmp1 = tmp1->next;
        p1 = p1->next;
        q1 = q1->next;
    }
    tmp1->next = new point(p1->x, p1->y, nullptr);
    // tmp->begin = tmp->begin->next;
    pathFunc(tmp);
    return tmp;
}

void ES(double toiu){
    // cout << toiu << endl;
    for(int i = 0; i < numPopulations; ++i) {
        path *tmp = mutation(population[i], toiu);
        if(compareTwoPath(tmp, population[i]) > 0){
            population[i] = tmp;
            population[i] = combination1(population[i], pPath[i]);
        }
        // population[i] = combination1(population[i], gPath);
    }
    updateBestPath();
    // for(numPopulations; numPopulations < populationMax; ++numPopulations) {
    //     combination1(population[rand() % numPopulations], population[rand() % numPopulations]);
    // }
}

void PSOES(){
    // for(int i = 0; i < 1000; ++i) {
    //     v[i] = 1;
    // }
    

    int loop = 1;
    point *p = population[0]->begin;
    while(p != nullptr){
        ++dim;
        p = p->next;
    }
    for(int i = 0; i < loop; ++i) {
        // ES();
        PSO();
    }
}