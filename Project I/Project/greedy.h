
void greedy_algorithm(){
	int k = -1, k1 = n + 1;
	currSeq[--k1] = 1;
	currSeq[++k] = 1;
	while(k + 1 < k1){
		int tmp, mn = 1e9, check = 0;
		for(int i = 2; i <= n; i++){
			if(!visited[i]){
				if(weights[currSeq[k]][i] < mn){
					mn = weights[currSeq[k]][i];
					tmp = i;
					check = 0;
				}
				if(weights[i][currSeq[k1]] < mn){
					mn = weights[i][currSeq[k1]];
					tmp = i;
					check = 1;
				}
			}
		}
		visited[tmp] = 1;
		if(check)
			currSeq[--k1] = tmp;
		else
			currSeq[++k] = tmp;
	}
	
	bestCost = cal_cost(currSeq);
	for(int l = 0; l <= n; ++l){
		bestSeq[l] = currSeq[l];
	}
}