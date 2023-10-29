#include<bits/stdc++.h>
using namespace std;
int s[1001][1001] = {}, x[1000] = {1}, t, n, m, u, v, ktra = 0;
bool vi[1001];

void hamiton(int k){
	if(ktra) return;
	if(k == n){
		if(s[x[k-1]][1]){
			ktra = 1;
			return;
		}
	}
	for(int i = 1; i <= n; ++i){
		if(s[x[k-1]][i] && !vi[i]){
			x[k] = i;
			vi[i] = true;
			hamiton(k+1);
			vi[i] = false;
		}
	}
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				s[i][j] = 0;
		while(m--){
			scanf("%d%d", &u, &v);
			s[u][v] = 1;
			s[v][u] = 1;
		}
		hamiton(1);
		if(ktra) printf("1\n");
		else printf("0\n");
		ktra = 0;
	}
}
