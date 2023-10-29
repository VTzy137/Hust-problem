#include<bits/stdc++.h>
using namespace std;

#define N 50
int n, c[N][N], step[N], optimal = 1e9, curDis = 0;
bool avail[N];

void come(int k){
	int currCity = step[k - 1];
	if(k == n){
		optimal = min(curDis + c[currCity][0], optimal);
		return;
	}
	for(int i = 1; i < n; ++i){
		if(!avail[i]){
			int cost = c[currCity][i];
			if(curDis + cost < optimal){
				step[k] = i;
				avail[i] = 1;
				curDis += cost;
				come(k + 1);
				avail[i] = 0;
				curDis -= cost;
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> c[i][j];
	come(1);
	cout << optimal;
}
