int nearPoint[8][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}};

typedef pair<double, pair<int, int>> pairDistance;
double gDistance[1000][1000] = {};
path* aStar(){
    set<pairDistance> aStar;
    int xStart = start->x, yStart = start->y, xFinish = finish->x, yFinish = finish->y;
    cout << xStart << " " << yStart << endl;
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
    cout << "ll" << endl;
    int stop = 100;
    while(--stop > 0){
        int tmp = graphStatus[xFinish][yFinish];
        xFinish = tmp / 1000;
        yFinish = tmp % 1000;
        p = new point((double) xFinish, (double) yFinish, p);
        if(xFinish == xStart && yFinish == yStart) break;
    }
    
    cout << "oo" << endl;
    res->begin = p;
    return res;
}

path *currPath, *gPath, *pPath[1000], *population[1000];
double w1, w2, w0, v[1000][1000] = {};
int numPopulations = 0, populationMax = 100, dim = 0;

void updateBestPath(){
    for (int i = 0; i < numPopulations; i++) {
        if(compareTwoPath(population[i], pPath[i]) > 0) pPath[i] = population[i];
        if(compareTwoPath(population[i], gPath) > 0) gPath = population[i];
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
path* mutation(path *p){
    point *tmp = p->begin, *offPoint = new point();
    path *offspring = new path(offPoint);
    while(tmp != nullptr) {
        double x1 = (rand() % 100)/50.0, y1 = (rand() % 100)/50.0;
        cout << x1 << y1;
        int i = 0;
        for(i; i < 8; ++i){
            if(checkValidPosition(tmp->x + x1*nearPoint[i][0], tmp->y + y1*nearPoint[i][1])){
                // cout << tmp->y << " " << tmp->x << endl;
                offPoint->next = new point(tmp->x + x1*nearPoint[i][0], tmp->y + y1*(double)nearPoint[i][1], nullptr);
                break;
            }
        }
        if(i == 8) offPoint->next = tmp;
        offPoint = offPoint->next;
        tmp = tmp->next;
    }
    offspring->begin = offspring->begin->next;
    pathFunc(offspring);
    return offspring;
}

path* combination1(path *p, path *q){
    if(q == nullptr) return nullptr;
    point *p1 = p->begin, *q1 = q->begin, *tmp1 = new point();
    path *tmp = new path(tmp1);
    while(p1 != nullptr) {
        int rr = rand() % 100;
        if((rr & 1) == 1) tmp1->next = p1;
        else tmp1->next = q1;
        tmp1 = tmp1->next;
        p1 = p1->next;
        q1 = q1->next;
    }
    tmp->begin = tmp->begin->next;
    pathFunc(tmp);
    return tmp;
}

void ES(){
    for(int i = 0; i < numPopulations; ++i) {
        population[i] = mutation(population[i]);
    }
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
        ES();
        PSO();
    }
}