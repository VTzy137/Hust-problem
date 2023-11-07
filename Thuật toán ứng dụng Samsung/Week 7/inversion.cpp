#include<bits/stdc++.h>
using namespace std;
int s[1000005], x[1000005], mod = 1e9+7, c = 0;
void merge(int l, int m, int r){
	if(r == l + 1)
		return;
	merge(l, (m+l)/2, m);
	merge(m, (m+r)/2, r);
	int k = l-1, j = l, i = m-1;
	while(++i < r){
		while(s[j] < s[i] && j < m)
			x[++k] = s[j++];
		x[++k] = s[i];
		c = (c + j - l) % mod;
	}
	while(j < m)
		x[++k] = s[j++];
	k = l - 1;
	while(++k < r){
		s[k] = x[k];
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = n-1; i >= 0; i--)
		scanf("%d", &s[i]);
	merge(0, n/2, n);
	cout << c;
}