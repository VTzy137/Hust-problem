#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, m = 1e9+7, f[1005][3] = {};
    f[1][0] = 1;
    f[1][1] = 1;
    f[1][2] = 1;
    cin >> n;
    for(int i = 2; i <= n; i++){
        f[i][0] = (f[i-1][1] + f[i-1][2]) % m;
        f[i][1] = (f[i-1][0] + f[i-1][2]) % m;
        f[i][2] = (f[i-1][0] + f[i-1][1] + f[i-1][2]) % m;
    }
    cout << (f[n][0] + f[n][1] + f[n][2]) % m;
}