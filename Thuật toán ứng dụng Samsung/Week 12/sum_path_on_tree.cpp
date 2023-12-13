#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> s[100001];
int n, u, v, w, visited[100001] = {}, length[100001] = {}, subs[100001] = {}, mx = 0;

void cal(int k){
	mx = max(length[k], mx);
	visited[k] = false;
	for(pair<int, int> i : s[k])
		if(visited[i.first]){
			length[i.first] = length[k] - i.second * (2 * subs[i.first] - n + 2);
			cal(i.first);
		}
}

void come(int k){
	visited[k] = true;
	for(pair<int, int> i : s[k])
		if(!visited[i.first]){
			come(i.first);
			subs[k] += subs[i.first] + 1;
			length[k] += length[i.first] + (subs[i.first] + 1) * i.second;
		}
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		scanf("%d%d%d", &u, &v, &w);
		s[u].push_back(make_pair(v, w));
		s[v].push_back(make_pair(u, w));
	}
	come(1);
	cal(1);
	cout << mx;
}