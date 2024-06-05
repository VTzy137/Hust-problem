#include<bits/stdc++.h>
using namespace std;
struct edges{
	int nextPoint;
	edges *next;
	edges(int nextPoint1, edges* next1){
		nextPoint = nextPoint1;
		next = next1;
	}
};
edges *s[50005];
int num[50005], low[50005], visited[50005], number = 0, num_bridges = 0, num_arti = 0;
void duyet(int point, int father){
	int num_component = (!father);
	edges *edge = s[point];
	while(edge){
		if(!visited[edge->nextPoint]){
			visited[edge->nextPoint] = 1;
			num[edge->nextPoint] = low[edge->nextPoint] = ++number;
			duyet(edge->nextPoint, point);
			low[point] = min(low[point], low[edge->nextPoint]);
			if(low[edge->nextPoint] > num[point])
				++num_bridges;
			if(low[edge->nextPoint] >= num[point])
				--num_component;
		}
		else if(edge->nextPoint != father)
			low[point] = min(low[point], num[edge->nextPoint]);
		edge = edge->next;
    }
	if(num_component < 0)
		++num_arti;
}

int main(){
	int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &u, &v);
        s[u] = new edges(v, s[u]);
        s[v] = new edges(u, s[v]);
    }
	for(int i = 1; i <= n; ++i)
		if(!visited[i]){
			visited[i] = 1;
			num[i] = low[i] = ++number;
			duyet(i, 0);
		}
	cout << num_arti << " " << num_bridges;
}