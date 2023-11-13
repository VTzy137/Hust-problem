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
edges *s[500001]; // luu ds canh do dai tu nho den lon 
int n, edge = -1, c[1001][1001] = {}, seq[1001] = {}; // luu cac canh va luu thu tu thanh pho tham
int k = -1, ci = 1, x[1001] = {}, x1[1001] = {}, pa[1001]= {}, deep[1001] = {};
bool vi[1001] = {};
int main(){
    cin >> n;
	if(n > 100){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				scanf("%d", &c[i][j]);
				if(i < j)
					s[++edge] = new edges(i, j, c[i][j]);
			}
		}
		// duyet duong di theo cay khung
		sort(s, s + ++edge, [](edges *a, edges *b)->bool{
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
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				scanf("%d", &c[i][j]);
				if(i != j)
					s[++edge] = new edges(i, j, c[i][j]);
			}
		}
		sort(s, s + ++edge, [](edges *a, edges *b)->bool{
			return a->c < b->c;
		});
		pa[1] = 1;
		while(ci < n){
			int u = s[++k]->i, v = s[k]->j, tmp = u, kt = 0;
			while(tmp){
				if(tmp == v){
					kt = 1;
					break;
				}
				tmp = x[tmp];
			}
			if(kt)
				continue;
			if(!x1[u] && !x[v]){
				++ci;
				x1[u] = v;
				x[v] = u;
			}
		}
		int u = 0, v = 0;
		for(int i = 1; i <= n; ++i){
			if(!x1[i])
				u = i;
			if(!x[i])
				v = i;
		}
		k = 0;
		seq[0] = 1;
		x[v] = u;
		x1[u] = v;
		int tmp = x1[1];
		while(tmp != 1){
			seq[++k] = tmp;
			tmp = x1[tmp];
		}
		seq[++k] = 1;
	}
	for(int i = 0; i <= n; ++i)
		vi[i] = 1;
	for(int o = 0; o < 5000; ++o){
		int cmin = 0, p = -1;
		for(int i = 1; i < n; ++i)
			if(vi[seq[i]] && c[seq[i-1]][seq[i]] + c[seq[i]][seq[i+1]] > cmin){
				p = i;
				cmin = c[seq[i-1]][seq[i]] + c[seq[i]][seq[i+1]];
			}
		if(p == -1){
			for(int i = 0; i < n; ++i)
				vi[i] = 1;
			continue;
		}
		int tmp = seq[p], j = p, cmax = 20000;
		for(int i = p; i > 0; --i)
			seq[i] = seq[i-1];
		for(int i = 1; i < n; ++i){
			seq[i-1] = seq[i];
			if(c[seq[i-1]][tmp] + c[tmp][seq[i+1]] - c[seq[i-1]][seq[i+1]] <= cmax){
				cmax = c[seq[i-1]][tmp] + c[tmp][seq[i+1]] - c[seq[i-1]][seq[i+1]];
				j = i;
			}
		}
		for(int i = n - 1; i > j; --i)
			seq[i] = seq[i-1];
		seq[j] = tmp;
		if(j == p)
			vi[seq[j]] = 0;
	}
	if(n < 101){
		int test = 10;
		while(test--){
			for(int i = 0; i < n - 4; ++i){
				int tmp = c[seq[i]][seq[i+1]];
				for(int j = i + 2; j < n - 1; ++j){
					int tmp1 = c[seq[j-1]][seq[j]];
					for(int k = j + 1; k < n; ++k){
						if(tmp + tmp1 + c[seq[k]][seq[k+1]] > c[seq[i]][seq[j]] + c[seq[k]][seq[i+1]] + c[seq[j-1]][seq[k+1]]){
							int temp_seq[j-i];
							for(int l = 1; l < j-i; ++l){
								temp_seq[l] = seq[i+l];
							}
							for(int l = j; l <= k; ++l){
								seq[l-(j-i-1)] = seq[l];
							}
							for(int l = 1; l < j-i; ++l){
								seq[i+(k+1-j)+l] = temp_seq[l];
							}
						}
					}
				}
			}
		}
	}
    cout << n << endl;
	for(int i = 0; i <= n; ++i)
		cout << seq[i] << " ";
}
