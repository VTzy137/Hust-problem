#include <bits/stdc++.h>
using namespace std;
int n, m, q, r1, c1, r2, c2, c[1001][1001] = {};
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        int tmp = 0, tmp1;
        for(int j = 1; j <= m; ++j){
            scanf("%d", &tmp1);
            tmp += tmp1;
            c[i][j] += c[i-1][j] + tmp;
        }
    }
    cin >> q;
    while(q--){
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        printf("%d\n", c[r2][c2] + c[r1-1][c1-1] - c[r2][c1-1] - c[r1-1][c2]);
    }
}