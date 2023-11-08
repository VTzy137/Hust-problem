#include <bits/stdc++.h>
using namespace std;
struct edges{
    int i, j, c = 0;
    edges(int i1, int j1, int c1 = 0){
        i = i1;
        j = j1; 
        c = c1;
    }
};
edges *s[500001];
int ss[1001][1001], pa[1001]= {}, deep[1001] = {}, tmp, tmp1;
bool vi[1001];
int main(){
    int n, p = -1, k = -1, c = 1, x[1001] = {}, x1[1001] = {};
    cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &ss[i][j]);
			if(i < j)
				s[++p] = new edges(i, j, ss[i][j]);
		}
	}
	if(n > 100){
		sort(s, s + ++p, [](edges *a, edges *b)->bool{
			return a->c < b->c;
		});
		while(c < n){
			int i = s[++k]->i, j = s[k]->j, u = i, v = j, tmp = c;
			while(pa[u]) u = pa[u];
			while(pa[v]) v = pa[v];
			if(u != v){
				if(!x[i]){
					if(!x[j]){
						x[i] = j;
						x[j] = i;
						++c;
					}
					else if(!x1[j]){
						x[i] = j;
						x1[j] = i;
						++c;
					}
				}
				else if(!x1[i]){
					if(!x[j]){
						x1[i] = j;
						x[j] = i;
						++c;
					}
					else if(!x1[j]){
						x1[i] = j;
						x1[j] = i;
						++c;
					}
				}
				if(c > tmp){
					if(deep[u] < deep[v]){
						pa[u] = v;
					}
					else{
						pa[v] = u;
						deep[u] = max(deep[u], deep[v] + 1);
					}
				}
			}
		}
		int u = 0, v = 0;
		for(int i = 1; i <= n; ++i){
			if(!x1[i]){
				if(!u)
					u = i;
				else
					v = i;
			}
		}
		k = 0;
		pa[0] = 1;
		x1[v] = u;
		x1[u] = v;
		tmp = 1; tmp1 = x[1];
		while(tmp1 != 1){
			pa[++k] = tmp1;
			if(x[tmp1] != tmp){
				tmp = tmp1;
				tmp1 = x[tmp1];
			}
			else{
				tmp = tmp1;
				tmp1 = x1[tmp1];
			}
		}
		pa[++k] = 1;
	}
    else{
        int visited[1005];
        vector<int> result;
        int current = 1;
		pa[++k] = 1;
        visited[current] = 1;

        while(1){
            int next = -1;
            int min_distance = INT_MAX;
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && ss[current][j] < min_distance) {
                    min_distance = ss[current][j];
                    next = j;
                }
            }
            if (next == -1) {
                break; 
            }
			pa[++k] = next;
            visited[next] = 1;
            current = next;
        }
		pa[++k] = 1;
    }

	for(int o = 0; o < 1000000 / n; ++o){
		c = 0;
		for(int i = 1; i < k; ++i){
			if(ss[pa[i-1]][pa[i]] + ss[pa[i]][pa[i+1]] > c && !vi[i]){
				p = i;
				c = ss[pa[i-1]][pa[i]] + ss[pa[i]][pa[i+1]];
			}
		}
		vi[p] = true;
		int j = 0;
		tmp = pa[p];
		for(int i = 1; i < k; ++i){
			tmp1 = ss[pa[i-1]][pa[i]] + ss[pa[i]][pa[i+1]];
			c += tmp1;
			pa[p] = pa[i];
			pa[i] = tmp;
			if(ss[pa[i-1]][pa[i]] + ss[pa[i]][pa[i+1]] + ss[pa[p-1]][pa[p]] + ss[pa[p]][pa[p+1]] < c){
				j = i;
			}
			pa[i] = pa[p];
			pa[p] = tmp;
			c -= tmp1;
		}
		if(j){
			pa[p] = pa[j];
			pa[j] = tmp;
			vi[j] = false;
			vi[p] = false;
		}
	}
	cout << n << endl;
	for(int i = 0; i < k; ++i){
		cout << pa[i] << " ";
	}
}
