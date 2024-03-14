#include<stdio.h>
struct node{
	int val;
	node* next = NULL;
	node(int v, node* n){
		this->val = v;
		this->next = n;
	}
};
node *db[1000002], *de[1000002];
int p[1000002] = {}, pq[1000002], a[1000002], q = -1, cMin = 1e9;

int main(){
    int n, m, i, j, sum = 0;
	scanf("%d", &n);
	for(int k = 0; k < n; ++k) scanf("%d", &a[k]);
	scanf("%d", &m);
	for(int k = 0; k < m; ++k){
		scanf("%d%d", &i, &j);
		db[i] = new node(k, db[i]);
		de[j] = new node(k, de[j]);
	}

	for(int k = 0; k < n; ++k){
		if(a[k] < cMin)	cMin = a[k];
		if(db[k] != 0){
			int tmp = q;
			while(p[tmp] > cMin) p[tmp--] = cMin;
			node *temp = db[k];
			while(temp != 0){
				p[++q] = a[k];
				pq[temp->val] = q;
				temp = temp->next;
			}
			cMin = a[k];
		}
		if(de[k] != 0){
			int tmp = q;
			while(p[tmp] > cMin) p[tmp--] = cMin;
			cMin = a[k];
			node *temp = de[k];
			while(temp != 0){
				sum += p[pq[temp->val]];
				temp = temp->next;
			}
		}
	}
	printf("%d", sum);
}
