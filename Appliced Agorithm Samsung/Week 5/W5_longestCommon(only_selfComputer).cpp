#include<bits/stdc++.h>
using namespace std;
vector<int> s[10005];
int main(){
	int n, m, l = 0, x, seq[10005] = {};
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		s[x].push_back(i);
	}
	for(int i = 0; i < m; ++i){
		scanf("%d", &x);
		if(s[x].size())
			for(int j = s[x].size() - 1; j >= 0; --j){
				int jt = s[x][j], tmp = seq[--jt] + 1;
				while(seq[++jt] < tmp) seq[jt] = tmp;
				l = max(tmp, l);
			}
    }
	cout << l;
}
// Ban nay ngan hon nma chi chay duoc tren may minh con Hustack bi tran bo nho
// Submit thi submit ban kia