#include<bits/stdc++.h>
using namespace std;
int s[22][1000001], p[22] = {1};
int main(){
    int n, m, i, j, k, c = 0;
    for(i = 1; i <= 21; ++i) p[i] = 2 * p[i-1]--;
    scanf("%d", &n);
    for(i = 0; i < n; ++i){ 
        k = 0;
        scanf("%d", &s[0][i]);
        while(i - p[++k] >= 0) s[k][i-p[k]] = min(s[k-1][i-p[k-1]], s[k-1][i-p[k]]);
    }
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &i, &j);
        k = log2(j-i+1);
        c += min(s[k][i], s[k][j-p[k]]);
    }
    printf("%d", c);
}