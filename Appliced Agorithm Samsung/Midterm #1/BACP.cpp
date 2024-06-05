#include <bits/stdc++.h>

using namespace std;

int n, m, c[20], a[20][20], x[50], mn = 1e9, cpp[10];

bool ktra(int k, int i){
    for(int j = 1; j < k; ++j){
        if(a[k][j]){
            if(x[j] < i)
                return false;
        }
    }
    return true;
}

void thu(int k){
    if(k == n + 1){
        int mx = 0;
        for(int i = 0; i < m; ++i){
            mx = max(cpp[i], mx);
        }
        mn = min(mn, mx);
        return;
    }
    for(int i = 0; i < m; ++i){
        if(ktra(k, i)){
            if(cpp[i] + c[k] < mn){
                x[k] = i;
                cpp[i] += c[k];
                thu(k + 1);
                cpp[i] -= c[k];
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    thu(1);
    cout << mn;
}
