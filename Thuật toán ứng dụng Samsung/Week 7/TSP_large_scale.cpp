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
int n, p = -1, k = -1, ci = 1;
edges *s[500001]; // luu ds canh do dai tu nho den lon 
int c[1001][1001] = {}, seq[1001] = {}; // luu cac canh va luu thu tu thanh pho tham
bool vi[1001] = {};
int main(){
    cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &c[i][j]);
			if(i < j && n > 100)
				s[++p] = new edges(i, j, c[i][j]);
		}
	}
	if(n > 100){
		int x[1001] = {}, x1[1001] = {}, pa[1001]= {}, deep[1001] = {};
		// duyet duong di theo cay khung nho
		sort(s, s + ++p, [](edges *a, edges *b)->bool{
			return a->c < b->c;
		});
		while(ci < n){
			int u = s[++k]->i, v = s[k]->j;
			while(pa[u]) u = pa[u];
			while(pa[v]) v = pa[v];
			if(u != v){
				int i = s[k]->i, j = s[k]->j, tmp = ci;
				if(!x[i]){
					if(!x[j]){
						x[i] = j;
						x[j] = i;
						++ci;
					}
					else if(!x1[j]){
						x[i] = j;
						x1[j] = i;
						++ci;
					}
				}
				else if(!x1[i]){
					if(!x[j]){
						x1[i] = j;
						x[j] = i;
						++ci;
					}
					else if(!x1[j]){
						x1[i] = j;
						x1[j] = i;
						++ci;
					}
				}
				if(ci > tmp){
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
		seq[0] = 1;
		x1[v] = u;
		x1[u] = v;
		int tmp = 1, tmp1 = x[1];
		while(tmp1 != 1){
			seq[++k] = tmp1;
			if(x[tmp1] != tmp){
				tmp = tmp1;
				tmp1 = x[tmp1];
			}
			else{
				tmp = tmp1;
				tmp1 = x1[tmp1];
			}
		}
		seq[++k] = 1;
		// thuc hien leo doi
		int ll = 7;
		for(int i = 0; i < 3 * n; i++){
			int u = -1, v = 0, mx = 0, mn = 5000, co = 0;
			for(int j = 0; j < n; j++){
				if(!vi[seq[j]]){
					++co; 
					if(c[seq[j]][seq[j+1]] > mx){
						u = j;
						mx = c[seq[j]][seq[j+1]];
					}
				}
			}
			if(co < n / 3){
				if(ll--){
					for(int j = 0; j < 1001; j++)
						vi[j] = 0;
					continue;
				}
				else
					break;
			}
			for(int j = 0; j < n && j != u; j++){
				if(c[seq[u]][seq[j]] + c[seq[u+1]][seq[j+1]] <= mn){
					v = j;
					mn = c[seq[u]][seq[j]] + c[seq[u+1]][seq[j+1]];
				}
			}
			vi[seq[u]] = 1;
			if(v < u){
				int tmp = v;
				v = u;
				u = tmp;
			}
			int kt = (v - u - 1) / 2;
			for(int j = 0; j < kt; j++){
				int tmp = seq[u + 1 + j];
				seq[u + 1 + j] = seq[v - j];
				seq[v - j] = tmp;
			}
		}
	}
    else{
		int best = 1e6, best_seq[105] = {};
        bool visited[105] = {};

        int current = 1;
		seq[++k] = 1;
        while(1){
            int next = -1, min_distance = INT_MAX;
            for(int j = 2; j <= n; j++){
                if(!visited[j] && c[current][j] < min_distance){
                    min_distance = c[current][j];
                    next = j;
                }
            }
            if(next == -1)
                break; 
			seq[++k] = next;
            visited[next] = 1;
            current = next;
        }
		seq[++k] = 1;

		for(int o = 0; o < 10000; ++o){
			if(o % 1000 == 0){
				for(int i = 0; i < 101; ++i){
					visited[o] = 1;
				}
			}
			int cmin = 0;
			p = -1;
			for(int i = 1; i < n; ++i){
				if(visited[seq[i]] && c[seq[i-1]][seq[i]] + c[seq[i]][seq[i+1]] > cmin){
					p = i;
					cmin = c[seq[i-1]][seq[i]] + c[seq[i]][seq[i+1]];
				}
			}
			if(p == -1)
				break;
			int tmp = seq[p], j = p;
			int tmp1 = c[seq[p-1]][tmp] + c[tmp][seq[p+1]] - c[seq[p-1]][seq[p+1]];
			cmin = 1000;
			// cout << "p:" << p << endl;
			for(int i = p; i > 0; --i)
				seq[i] = seq[i-1];
			for(int i = 1; i < n; ++i){
				seq[i-1] = seq[i];
				if(c[seq[i-1]][tmp] + c[tmp][seq[i+1]] - c[seq[i-1]][seq[i+1]] < cmin){
					cmin = c[seq[i-1]][tmp] + c[tmp][seq[i+1]] - c[seq[i-1]][seq[i+1]];
					j = i;
				}
			}
			if(tmp1 < cmin)
				j = p;
			for(int i = n - 1; i > j; --i){
				seq[i] = seq[i-1];
			}
			seq[j] = tmp;
			if(j == p){
				visited[seq[j]] = 0;
			}
		}
	}
	// in ket qua
    cout << n << endl;
	for(int i = 0; i <= n; ++i)
		cout << seq[i] << " ";
}
