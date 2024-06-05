
typedef pair<double, pair<int, int>> pairDistance;
double gDistance[1000][1000] = {};
int visited[1000][1000] = {};
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
            if(visited[x][y] == 0 && checkValidPoint(x, y)){
                visited[x][y] = past;
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
    int stop = 1000;
    while(--stop > 0){
        int tmp = visited[xFinish][yFinish];
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
int numPopulations = 5, populationMax = 100, pathLen;

void decreaseDimension(path *p) {
    point *q = p->begin;
    while(q->next != nullptr && q->next->next != nullptr) {
        q->next = q->next->next;
        q = q->next;
    }
}

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

double w0PSO = 0.5, w1PSO = 0.2, w2PSO = 0.05, v[1000][200][2] = {};
void updateV(int i){
    int j = 0;
    point *p = population[i]->begin, *pp = pPath[i]->begin, *pn = gPath->begin;
    while(p != nullptr) {
        v[i][j][0] = w0PSO * v[i][j][0] + w1PSO * (pp->x - p->x) + w2PSO * (pn->x - p->x);
        v[i][j][1] = w0PSO * v[i][j][1] + w1PSO * (pp->y - p->y) + w2PSO * (pn->y - p->y);
        ++j;
        p = p->next;
        pp = pp->next;
        pn = pn->next;
    }
}

double wVPSO = 0.1;
void PSO(){
    updateBestPath();
    for(int i = 0; i < numPopulations; i++) {
        updateV(i);
        point *p = population[i]->begin;
        for(int j = 0; j < pathLen; ++j) {
            p->x += v[i][j][0] * wVPSO;
            p->y += v[i][j][1] * wVPSO;
            p = p->next;
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

double est = 1.0;
path* mutation(path *p, double toiu){
    point *tmp = p->begin, *offPoint = new point(tmp->x, tmp->y, nullptr);
    path *offspring = new path(offPoint);
    tmp = tmp->next;
    double keke = rand() % (int)(pathLen*est/4), x1 = (rand() % 200 - 100) / (toiu), y1 = (rand() % 200 - 100) / (toiu), stt = 0, posPoint = rand() % pathLen;
    while(tmp->next != nullptr) {
        double wei = 1 - min(1.0, abs(stt++ - posPoint) / keke);
        offPoint->next = new point(tmp->x + x1 * wei, tmp->y + y1 * wei, nullptr);
        // if(checkValidLine(offPoint, offPoint->next) == false) return p;
        if(checkValidPoint(offPoint) == false) return p;
        offPoint = offPoint->next;
        tmp = tmp->next;
    }
    offPoint->next = new point(tmp->x, tmp->y, nullptr);
    // offspring->begin = offspring->begin->next;
    pathFunc(offspring);
            // cout << endl << "fidddd" << endl ;
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
            population[i] = combination1(tmp, pPath[i]);
            // population[i] = tmp;
        }
        // population[i] = combination1(population[i], gPath);
    }
    updateBestPath();
    // for(numPopulations; numPopulations < populationMax; ++numPopulations) {
    //     combination1(population[rand() % numPopulations], population[rand() % numPopulations]);
    // }
}

void PSOES(double toiu, int loop){
    // for(int i = 0; i < 1000; ++i) {
    //     v[i] = 1;
    // }
    
    for(int i = 0; i < loop; ++i) {
        est += 0.7/loop;
        toiu += 30.0 / loop;
        // if(i < loop/10) ES(toiu/10);
        ES(toiu);
        PSO();
    }
}