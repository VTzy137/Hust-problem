#include<bits/stdc++.h>
using namespace std;
vector<int> s[100001];
int n, u, v, w[100001], mx0[100001] = {}, mx1[100001] = {};
bool visited[100001];

void come(int k){
	mx1[k] = w[k];
	for(int i : s[k]){
		if(!visited[i]){
			visited[i] = 1;
			come(i);
			mx0[k] += max(mx0[i], mx1[i]);
			mx1[k] += mx0[i];
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &u, &v);
		s[u].push_back(v);
		s[v].push_back(u);
	}
	visited[1] = true;
	come(1);
	cout << max(mx1[1], mx0[1]);
}