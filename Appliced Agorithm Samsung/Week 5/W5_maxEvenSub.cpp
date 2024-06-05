#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, x, mx = 0, mnE = 0, mnO = 1e6, cur = 0;
    scanf("%lld", &n);
    while(n--){
        scanf("%lld", &x);
        cur += x;
        if(cur & 1){
            mnO = min(mnO, cur);
            mx = max(mx, cur - mnO);
        }
        else{
            mnE = min(mnE, cur);
            mx = max(mx, cur - mnE);
        }
    }
    printf("%lld", mx);
}