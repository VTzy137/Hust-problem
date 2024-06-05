#include <bits/stdc++.h>
using namespace std;
int n, q, j=0, mx=0, a[1000001]={};
int main(){
    cin >> n >> q;
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
        a[i] += a[i-1];
        while(a[i] - a[j] > q) ++j;
        mx = max(mx, i - j);
    }
    cout << mx;
}