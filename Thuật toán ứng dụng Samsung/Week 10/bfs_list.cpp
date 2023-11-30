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
int n, m, u, v, x[100005], p = -1, k = 0;
bool visited[100005];
void them(int u, int v){
	node *tmp = s[u];
	while(tmp->n){
		if(tmp->n->v > v)
			break;
		tmp = tmp->n;
	}
	tmp->n = new node(v, tmp->n);
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		s[i] = new node(0, 0);
	while(m--){
		scanf("%d%d", &u, &v);
		them(u, v);
		them(v, u);
	}
	x[0] = 1;
	visited[1] = true;
	visited[0] = true;
	while(1){
		while(++p <= k){
			printf("%d ", x[p]);
			node *tmp = s[x[p]]->n;
			while(tmp){
				if(!visited[tmp->v]){
					x[++k] = tmp->v;
					visited[tmp->v] = true;
				}
				tmp = tmp->n;
			}
		}
		int i = 1;
		for(i; i <= n; ++i){
			if(!visited[i]){
				break;
			}
		}
//		cout << i << endl;
		if(i > n)
			break;
		visited[i] = true;
		x[p--] = i;
		++k;
	}
}
