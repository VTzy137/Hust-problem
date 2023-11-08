#include <bits/stdc++.h>

using namespace std;

int n, m, c[50][50], x[50], cost = 0, co = 0;
bool vi[50];

void thu(int k){
    if(k == n){
        if(cost + c[x[k-1]][1] <= m){
            ++co;
        }
        return;
    }
    for(int i = 2; i <= n; ++i){
        if(!vi[i]){
            if(cost + c[x[k-1]][i] < m){
                x[k] = i;
                vi[i] = true;
                cost += c[x[k-1]][i];
                thu(k + 1);
                cost -= c[x[k-1]][i];
                vi[i] = false;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%d", &c[i][j]);
        }
    }
    x[0] = 1;
    thu(1);
    cout << co;
}
