#include<bits/stdc++.h>
using namespace std;
int N, M, mn = 1e6, cost = 0, p = -1, sl = 0, pmn;
int Q[51][1001], d[1001][1001], q[51], qi[51] = {}, x[1001] = {}, xmn[1001] = {};
bool visited[51];
clock_t start, endd;
void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            scanf("%d", &Q[i][j]);
        }
    }
    for(int i=0; i<=M; ++i){
        for(int j=0; j<=M; ++j){
            scanf("%d", &d[i][j]);
        }
    }
    for(int i=1; i<=N; ++i){
        scanf("%d", &q[i]);
    }
}

int chiphi(){
    int cp = d[0][x[0]];
    for(int i=1; i<=p; ++i) cp += d[x[i-1]][x[i]];
    return cp;
}

void tim(){
    endd = clock();
    if(endd - start > 500) return;
    if(!sl){
        if(mn > chiphi() + d[x[p]][0]){
            pmn = p;
            for(int i=0; i<=p; ++i) xmn[i] = x[i];
        }
    }
    for(int i=1; i<=N; ++i){
        if(visited[i]){
            x[++p] = i;
            if(chiphi() < mn){
                visited[i] = false;
                --sl;
                tim();
                ++sl;
                visited[i] = true;
            }
            --p;
        }
    }
}

void chon(int a){
    int kt = 0;
    for(int i=1; i<=N; ++i) if(qi[i] < q[i]) kt = 1;
    if(!kt) tim();
    else for(int i=a+1; i<=M; ++i){
            ++sl;
            visited[i] = true;
            for(int j=1; j<=N; ++j) qi[j] += Q[j][i];
            chon(i);
            for(int j=1; j<=N; ++j) qi[j] -= Q[j][i];
            visited[i] = false;
            --sl;
        }
}

int main(){
    start = clock();
    input();
    chon(0);
    cout << pmn << endl;
    for(int i=0; i<=pmn; ++i) cout << xmn[i] << " ";
}
