#include<bits/stdc++.h>
using namespace std;
struct node{
    int i, j, step;
    node(int i1, int j1, int step1){
        i = i1;
        j = j1;
        step = step1;
    }
};
node *x[1000005];
int a[1005][1005] = {}, n, m, r, c, p = -1, k = 0, ktra = 0;
bool vi[1005][1005];
void thu(int i, int j){
    if(!a[i][j] && !vi[i][j]){
        x[++k] = new node(i, j, x[p]->step + 1);
        vi[i][j] = true;
    }
    if(i > n || j > m || !i || !j)
        ktra = x[k]->step;
}
int main(){
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    if(a[r][c])
        cout << -1;
    else{
        x[0] = new node(r, c, 0);
        while(++p <= k && !ktra){
            int i = x[p]->i, j = x[p]->j;
            thu(i - 1, j);
            thu(i, j - 1);
            thu(i + 1, j);
            thu(i, j + 1);
        }
        if(ktra)
            cout << ktra;
        else
            cout << -1;
    }
}