#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node* next = NULL;
	node(int v, node* n){
		this->val = v;
		this->next = n;
	}
};
node* s[10005];

int main(){
	int n, m, l = 0, x, y, seq[10005] = {};
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		node *p = new node(i, s[x]);
		s[x] = p;
	}
	for(int i = 0; i < m; ++i){
		scanf("%d", &y);
		if(s[y]){
			node* p = s[y];
			while(p != NULL){
				int jt = p->val, tmp = seq[--jt] + 1;
				while(seq[++jt] < tmp) seq[jt] = tmp;
				l = max(tmp, l);
				p = p->next;
			}
		}
	}
	cout << l;
}
