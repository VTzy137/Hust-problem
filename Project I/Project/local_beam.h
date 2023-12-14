
// Choose best k-state and generate new path from this k-state
void local_beam(){
    
    startTSP = clock();

    heuristic(10);
    sort(state, state + 1000, [](status *a, status *b)->bool{
        return a->cost < b->cost;
    });
    int i = 0;
    for(int test = 1; test < 5000; test++){
        // cout << bestCost << endl;
        ++i;
        for(int l = 0; l <= n; l++){
            currSeq[l] = state[i]->s[l];
        }
        heuristic(state[i]->cost / 100);
        state[i]->cost = 1e6;
        if(test % 10 == 0){
            i = 1;
            stt = 100;
            sort(state, state + 20000, [](status *a, status *b)->bool{
                return a->cost < b->cost;
            });
        }
    }

	endTSP = clock();
}