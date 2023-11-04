#include<bits/stdc++.h>
using namespace std;
struct node{
    int v, c;
    node *n, *e;
    node(int v1, int c1, node *n1){
        v = v1;
        c = c1;
        n = n1;
    }
};
node *x[40001], *x1[40001];
int n, m, s, t, u, v, c, mx = 0, p = 1;
bool vi[40001];

void thu(int k){
    if(k == t){
        int f = 1e9;
        for(int i = 1; i < p; ++i)
            f = min(f, x1[i]->c);
        for(int i = 1; i < p; ++i){
            x1[i]->c -= f;
            x1[i]->e->c += f;
        }
        mx += f;
        return;
    }
    node *temp = x[k];
    while(temp){
        if(!vi[temp->v] && temp->c){
            x1[p++] = temp;
            vi[temp->v] = true;
            thu(temp->v);
            vi[temp->v] = false;
            p--;
        }
        temp = temp->n;
    }
}

int main(){
    cin >> n >> m >> s >> t;
    while(m--){
        scanf("%d%d%d", &u, &v, &c);
        x[u] = new node(v, c, x[u]);
        x[v] = new node(u, 0, x[v]);
        x[u]->e = x[v];
        x[v]->e = x[u];
    }
    vi[s] = true;
    thu(s);
    cout << mx;
}