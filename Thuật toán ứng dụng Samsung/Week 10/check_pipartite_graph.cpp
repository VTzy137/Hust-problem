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
int n, m, u, v, x[100005] = {}, kt = 0;
void duyet(int u){
	if(kt)
		return;
	node *tmp = s[u];
	while(tmp){
		if(!x[tmp->v]){
			x[tmp->v] = -x[u];
			duyet(tmp->v);
		}
		else if(x[tmp->v] == x[u]){
			kt = 1;
			return;
		}
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
	x[1] = 1;
	duyet(1);
	if(kt)
		cout << 0;
	else
		cout << 1;
}
