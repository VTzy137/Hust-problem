#include<bits/stdc++.h>
using namespace std;
int n, q, tmp, tmp1, a[100001] = {};
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &tmp);
        a[i] = tmp + a[i-1];
    }
    cin >> q;
    while(q--){
        scanf("%d%d", &tmp, &tmp1);
        printf("%d\n", a[tmp1] - a[tmp-1]);
    }
}