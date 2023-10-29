#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u, v, w;
    edge(int u1, int v1, int w1){
        u = u1;
        v = v1;
        w = w1;
    }
};
int x[10001]= {}, deep[10001] = {};
edge *s[100000];

int main(){
    // freopen("inp.txt", "r", stdin);
	int n, m, u, v, w, p = -1, count = 0, weight = 0;
    cin >> n >> m;
    while(m--){
        scanf("%d%d%d", &u, &v, &w);
        s[++p] = new edge(u, v, w);
    }
    sort(s, s + ++p, [](edge *a, edge *b)->bool{
        return a->w <= b->w;
    });
    p = -1;
    while(++count < n){
        while(1){
            edge *temp = s[++p];
            u = temp->u; v = temp->v;
            while(x[u] != 0) u = x[u];
            while(x[v] != 0) v = x[v];
            if(u != v){
                if(deep[u] < deep[v]){
                    x[u] = v;
                }
                else{
                    x[v] = u;
                    deep[u] = max(deep[u], deep[v] + 1);
                }
                weight += temp->w;
                break;
            }
        }
    }
    cout << weight;
}
