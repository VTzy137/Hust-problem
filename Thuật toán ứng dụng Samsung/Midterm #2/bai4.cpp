#include<bits/stdc++.h>
using namespace std;
int n, c[1001][1001] = {}, bestcp = 1e9, bestseq[1001] = {}, sequence[1001] = {}, ktra = 1;
bool visited[1005] = {};

int chi_phi(){
	int chiphi = 0;
	for(int k = 0; k < n; ++k)
		chiphi += c[sequence[k]][sequence[k+1]];
	return chiphi;
}

bool two(int bonus = 0, int begin = 0){
    for(int i = begin; i < n; ++i){
        for(int j = i + 3; j < n; ++j){
            if(c[sequence[i]][sequence[i+1]] + c[sequence[j-1]][sequence[j]] + bonus > c[sequence[i+1]][sequence[j]] + c[sequence[i]][sequence[j-1]]){
                for(int k = 1; k <= (j-i) / 2; ++k){
                    int tmp = sequence[i + k];
                    sequence[i + k] = sequence[j - k];
                    sequence[j - k] = tmp;
                }
                return true;
            }
        }
    }
    return false;
}

bool one(int bonus = 0, int begin = 0){
	for(int i = begin; i < n; ++i){
		for(int j = i; j < n; ++j){
			for(int k = 0; k < i-1; ++k){
				if(c[sequence[k]][sequence[k+1]] + c[sequence[i-1]][sequence[i]] + c[sequence[j]][sequence[j+1]] + bonus > c[sequence[k]][sequence[i]] + c[sequence[j]][sequence[k+1]] + c[sequence[i-1]][sequence[j+1]]){
					int temp_seq[j-i+1];
                    for(int l = 0; l <= j-i; ++l)
                        temp_seq[l] = sequence[i+l];
                    for(int l = j; l > k+(j+1-i); --l)
                        sequence[l] = sequence[l-(j-i+1)];
                    for(int l = 0; l <= j-i; ++l)
                        sequence[k+l+1] = temp_seq[l];
                    return true;
				}
			}
		}
	}
    return false;
}

bool heuristic(int bo = 0, int begin = 0){
    if(ktra)
        return two(bo, begin);
    else
        return one(bo, begin);
}

int curDis = 0;
void thamlam(int k){
	int currCity = sequence[k - 1];
	if(k == n){
		if(curDis + c[currCity][1] < bestcp){
            bestcp = curDis + c[currCity][1];
            for(int i = 0; i <= n; i++){
                bestseq[i] = sequence[i];
            }
        }
		return;
	}
	for(int i = 2; i <= n; ++i){
		if(!visited[i]){
			int cost = c[currCity][i];
			if(curDis + cost + (n-k) < bestcp){
				sequence[k] = i;
				visited[i] = 1;
				curDis += cost;
				thamlam(k + 1);
				visited[i] = 0;
				curDis -= cost;
			}
		}
	}
}

int main(){
    // freopen("test.txt", "r", stdin);
    clock_t start = clock();
    cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &c[i][j]);
    if(n < 20){
        sequence[0] = 1;
        sequence[n] = 1;
        thamlam(1);
        for(int i = 0; i <= n; ++i){
            sequence[i] = bestseq[i];
        }
        // cout << chi_phi() << endl;
        cout << n << endl; 
        for(int i = 0; i <= n; ++i){
            cout << bestseq[i] << " ";
        }
        return 0;
    }
    for(int i = 1; i <= n; i++)
        if(c[i][1] != c[1][i])
            ktra = 0;
	int k = -1, k1 = n + 1;
	sequence[--k1] = 1;
	sequence[++k] = 1;
	while(k + 1 < k1){
		int tmp, mn = 1e9, ktra = 0;
		for(int i = 2; i <= n; i++){
			if(!visited[i]){
				if(c[sequence[k]][i] < mn){
					mn = c[sequence[k]][i];
					tmp = i;
					ktra = 0;
				}
				if(c[i][sequence[k1]] < mn){
					mn = c[i][sequence[k1]];
					tmp = i;
					ktra = 1;
				}
			}
		}
		visited[tmp] = 1;
		if(ktra)
			sequence[--k1] = tmp;
		else
			sequence[++k] = tmp;
	}
    for(int test = 0; test < 120; test++){
        if(!heuristic()){
            if(bestcp > chi_phi()){
                for(int i = 0; i <= n; ++i)
                    bestseq[i] = sequence[i];
                bestcp = chi_phi();
            }
            ktra = 0;
            // heuristic(bestcp / 50, n / 2);
        }
    }
    // heuristic();
    // }
    if(bestcp > chi_phi()){
        for(int i = 0; i <= n; ++i)
            bestseq[i] = sequence[i];
        bestcp = chi_phi();
    }
    // cout << bestcp << endl;
    cout << n << endl;
	for(int k = 0; k < n; ++k)
		cout << bestseq[k] << " ";
}