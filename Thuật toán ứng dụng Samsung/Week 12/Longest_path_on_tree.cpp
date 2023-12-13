#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> s[100001];
int n, u, v, w, mx;
int  x[100001][2] = {};
bool visited[100001] = {};

int find(int x0){
	for(int i = 0; i <= n; ++i){
		visited[i] = false;
		x[i][1] = 0;
	}
	int p = -1, k = 0, j = 0;
	x[0][0] = x0;
	visited[x0] = true;
	while(++p < n){
		for(pair<int, int> i : s[x[p][0]]){
			if(!visited[i.first]){
				visited[i.first] = true;
				x[++k][0] = i.first;
				x[k][1] = x[p][1] + i.second;
			}
		}
	}
	for(int i = 0; i <= n; i++){
		if(x[i][1] > mx){
			mx = x[i][1];
			j = i;
		}
	}
	return x[j][0];
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &u, &v, &w);
		s[u].push_back(make_pair(v, w));
		s[v].push_back(make_pair(u, w));
	}
	find(find(1));
	cout << mx;
}
