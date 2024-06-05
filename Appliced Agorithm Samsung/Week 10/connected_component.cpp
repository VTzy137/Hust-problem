#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	node *n;
	node(int v1, node* n1){
		v = v1;
		n = n1;
	}
};
node *s[100005];
bool visited[100005];
void duyet(int u){
	node *tmp = s[u];
	while(tmp){
		if(!visited[tmp->v]){
			visited[tmp->v] = true;
			duyet(tmp->v);
		}
		tmp = tmp->n;
	}
}

int main(){
    int n, m, u, v, counter = 0;
	cin >> n >> m;
	while(m--){
		scanf("%d%d", &u, &v);
		s[u] = new node(v, s[u]);
		s[v] = new node(u, s[v]);
	}
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            visited[i] = true;
            duyet(i);
            ++counter;
        }
    }
	cout << counter;
}
