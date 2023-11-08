#include<bits/stdc++.h>
using namespace std;
int a, b, c, bfs[4000][3], p = -1, k = 0, kt = 0;
bool a1[1000][2], b1[1000][2];

void ktra(int at, int bt){
    if(at == 0)
        if(a1[bt][0]) return;
        else a1[bt][0] = true;
    else if(at == a)
        if(a1[bt][1]) return;
        else a1[bt][1] = true;
    else if(bt == 0)
        if(b1[at][0]) return;
        else b1[at][0] = true;
    else if(b1[at][1]) return;
    else b1[at][1] = true;
    bfs[++k][0] = at;
    bfs[k][1] = bt;
    bfs[k][2] = bfs[p][2] + 1;
    if(at == c || bt == c){
        cout << bfs[p][2] + 1;
        kt = 1;
    }
    return;
}

int main(){
    cin >> a >> b >> c;
    a1[0][0] = true; b1[0][0] = true;
    while(++p <= k && kt == 0){
        int at = bfs[p][0], bt = bfs[p][1], sum = at + bt;
        ktra(0, bt);
        ktra(at, 0);
        ktra(at, b);
        ktra(a, bt);
        ktra(max(0, sum - b), min(sum, b));
        ktra(min(sum, a), max(0, sum - a));
    }
    if(kt == 0) cout << -1;
}
