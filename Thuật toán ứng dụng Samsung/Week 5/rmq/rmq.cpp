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
node *db[1000002], *de[1000002];
int p[1000002] = {}, pq[1000002], cMin = 1e9, q = 0, a[1000002];

int main(){
    clock_t b = clock();
    freopen("inp.txt", "r", stdin);
    int n, m, i, j, sum = 0;
	cin >> n;
	for(int k = 1; k <= n; ++k)
		scanf("%d", &a[k]);
	cin >> m;
	for(int k = 1; k <= m; ++k){
		scanf("%d%d", &i, &j);
		db[i + 1] = new node(k, db[i + 1]);
		de[j + 1] = new node(k, de[j + 1]);
	}
    clock_t mi = clock();
	for(int k = 1; k <= n; ++k){
		cMin = min(cMin, a[k]);
		if(db[k] != 0){
			int tmp = q;
			while(p[tmp] > cMin)
				p[tmp--] = cMin;
			node *temp = db[k];
			p[++q] = a[k];
			while(temp != 0){
				pq[temp->val] = q;
				temp = temp->next;
			}
			cMin = a[k];
		}
		if(de[k] != 0){
			int tmp = q;
			while(p[tmp] > cMin)
				p[tmp--] = cMin;
			cMin = a[k];
			node *temp = de[k];
			while(temp != 0){
				sum += p[pq[temp->val]];
				temp = temp->next;
			}
		}
	}
    clock_t e = clock();
	cout << sum;
	cout << endl << mi - b << endl << e - mi;
}
