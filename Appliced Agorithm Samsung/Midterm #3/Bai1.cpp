#include<bits/stdc++.h>
using namespace std;
int n, x, c, a[1000001];
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        ++a[x];
        c += a[x+1] + a[x-1];
    }
    printf("%d", c % (int)(1e9+7));
}