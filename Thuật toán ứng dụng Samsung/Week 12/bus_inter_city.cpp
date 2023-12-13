#include<bits/stdc++.h>
using namespace std;
int n, m, i, j, mn = 1e6, cost = 0, c[10001], d[10001], cp[10001] = {}, h[10001] = {};
bool visited[10001], come[10001];
vector<int> s[10001], s1[10001];
void connect(int k, int t){
	if(t == d[i])
		return;
	for(int j : s[k])
		if(!come[j]){
			come[j] = true;
			s1[i].push_back(j);
			connect(j, t + 1);
		}
}
void duyet(int k){
	if(k == n){
		visited[n] = false;
		return;
	}
	if(cost > mn)
		return;
    i = k;
	come[k] = true;
    connect(k, 0);
    h[k] = 1e6;
    for(int j : s1[k])
        come[j] = false;
	come[k] = false;
	cp[k] = cost;
	cost += c[k];
	for(int k1 : s1[k]){
		if(!visited[k1]){
			visited[k1] = true;
			duyet(k1);
		}
		cp[k1] = min(cost, cp[k1]);
        h[k] = min(h[k], h[k1] + c[k]);
		mn = min(mn, h[k1] + cp[k1]);
    }
	cost -= c[k];
}
int main(){
	cin >> n >> m;
	for(i = 1; i <= n; i++)
		scanf("%d%d", &c[i], &d[i]);
	while(m--){
		scanf("%d%d", &i, &j);
		s[i].push_back(j);
		s[j].push_back(i);
	}
	visited[1] = true;
	duyet(1);
	cout << h[1];
}
