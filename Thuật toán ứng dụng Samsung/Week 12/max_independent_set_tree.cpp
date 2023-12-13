#include<bits/stdc++.h>
using namespace std;
vector<int> s[100001];
int n, u, v, mx1[100001], mx0[100001] = {}, visited[100001] = {};
void come(int k){
	visited[k] = 1;
	for(int i : s[k])
		if(!visited[i]){
			come(i);
			mx0[k] += max(mx0[i], mx1[i]);
			mx1[k] += mx0[i];
		}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &mx1[i]);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &u, &v);
		s[u].push_back(v);
		s[v].push_back(u);
	}
	come(1);
	cout << max(mx1[1], mx0[1]);
}