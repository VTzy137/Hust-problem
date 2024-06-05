#include<bits/stdc++.h>

using namespace std;

#define N 50
int n, K, n1, finish, c[N][N], visit[N], cmin = 1e9, currCost = 0, optimal = 1e9, v_ed[N];

void come(int k){
    int currPoint = visit[k - 1]; 
	if(k == finish){
        if(currCost + c[currPoint][0] < optimal)
		    optimal = currCost + c[currPoint][0];
		return;
	}
    for(int i = 1; i < n1; ++i){
        if(K && v_ed[i] == 0){
            currCost += c[currPoint][i];
            if(currCost + cmin * (finish - k) < optimal){
                visit[k] = i;
                ++v_ed[i];
                --K;
                come(k + 1);
                --v_ed[i];
                ++K;
            }
            currCost -= c[currPoint][i];
        }
        else if(v_ed[i] == 1){
            currCost += c[currPoint][i + n];
            if(currCost + cmin * (finish - k) < optimal){
                visit[k] = i + n;
                ++v_ed[i];
                ++K;
                come(k + 1);
                --v_ed[i];
                --K;
            }
            currCost -= c[currPoint][i + n];
        }
    }
}

int main(){
	cin >> n >> K;
	finish = 2 * n + 1;
	n1 = n + 1;
	for(int i = 0; i < finish; ++i)
		for(int j = 0; j < finish; ++j){
			scanf("%d", &c[i][j]);
            if(i!=j&&cmin>c[i][j])cmin=c[i][j];
        }
	come(1);
	cout << optimal;
	return 0;
}
