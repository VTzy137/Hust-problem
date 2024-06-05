#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	node *n;
	node(int v1, node* n1 = 0){
		v = v1;
		n = n1;
	}
};
node *s[100005], *s1[100005];
int n, m, u, v, x[100005], p = 0;
bool visited[100005];
void duyet(int u){
	visited[u] = true;
	printf("%d ", u);
	node *tmp = s[u];
	while(tmp){
		if(!visited[tmp->v])
			duyet(tmp->v);
		tmp = tmp->n;
	}
}

int main(){
	cin >> n >> m;
	while(m--){
		scanf("%d%d", &u, &v);
		if(s[u]){
			s1[u]->n = new node(v);
			s1[u] = s1[u]->n;
		}
		else{
			s[u] = new node(v);
			s1[u] = s[u];
		}
		if(s[v]){
			s1[v]->n = new node(u);
			s1[v] = s1[v]->n;
		}
		else{
			s[v] = new node(u);
			s1[v] = s[v];
		}
	}
	duyet(1);
}
