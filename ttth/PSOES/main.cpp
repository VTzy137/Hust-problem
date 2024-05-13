#include <bits/stdc++.h>
using namespace std;
#include "util/graph.h"
#include "util/path.h"
#include "util/agorithm.h"
int main(){
    clock_t startt = clock();
    inputGraph(2);
    freopen("out.txt", "w", stdout);
    changeToNewGraph();

    markObstacle();

    aStar();
    
    setPathFromAstar();
    pathLen = pathLength(astarRes);
    // cout << endl;
    resetGraphStatus();
    // astarRes = mutation(astarRes, 100);
    // astarRes = combination1(astarRes, population[0]);
    // astarRes = mutation(astarRes, 50);
    // astarRes = mutation(astarRes, 50);
    // astarRes = combination1(astarRes, population[0]);
    // astarRes = mutation(astarRes, 50);
    int estime = 50000;
    for(int i = 0; i < estime; ++i) {
        // est = 2 - i * 1.0 / estime;
        // ES(60.0*(i+estime)/estime);
        ES(100.0);
    }
    // cout << astarRes->angle << " " << astarRes->distance << " " << gPath->angle << " " << gPath->distance << endl;
    // cout << compareTwoPath(astarRes, gPath) << endl << endl;
    astarRes = gPath;
    point *p = astarRes->begin;
    while(p != nullptr) {
        cout << p->x << " " << p->y << endl;
        graphStatus[(int)p->x][(int)p->y] = -1;
        p = p->next;
    }
    pathFunc1(astarRes);
    cout << endl << "angle: " << astarRes->angle << "           distance: " << astarRes->distance << endl;
    // for(int i=125; i>75; --i){
    //     for(int j=75; j<175; ++j){
    //         if(graphStatus[j][i] == -1) cout << '-' << " ";
    //         else cout << (char) ('0' + !graphStatus[j][i]) << " ";
    //     }
    //     cout << endl;
    // }
    // double keke = rand() % 100 / 10.0, x1 = (rand() % 200 - 100) / (100.0 ), y1 = (rand() % 200 - 100) / (100.0), stt = 0, posPoint = rand() % pathLen;
    // cout << x1 << " " << y1 << " " << posPoint << " " << endl;
    //     double wei = 1 - pow(abs(1 - posPoint) / kk; cout << "wei " << wei << endl;
    // PSOES();
    
    changeToInitGraph();
    clock_t endd = clock();
    cout << endl << endd - startt;
}