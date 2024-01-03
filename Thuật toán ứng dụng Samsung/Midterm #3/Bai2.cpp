#include<bits/stdc++.h>
using namespace std;
long long n, a[200002] = {}, b[200002] = {}, tmp, c = 0, m = 1e9+7;
int main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    for(int i = 1; i < n; ++i)
        scanf("%lld", &b[i]);
    tmp = a[0];
    for(int i = 1; i < n; ++i){
        if(b[i] == 0){
            c = (c + tmp) % m;
            tmp = -a[i];
        }
        else if(b[i] == 1){
            c = (c + tmp) % m;
            tmp = a[i];
        } 
        else{
            tmp = (tmp * a[i]) % m;
        }
    }
    n = (c + tmp) % m;
    if(n < 0) n += m;
    printf("%lld", n);
}