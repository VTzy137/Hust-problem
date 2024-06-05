#include<bits/stdc++.h>
using namespace std;
struct edges{
    int u, v, w;
    edges(int u1, int v1, int w1){
        u = u1;
        v = v1;
        w = w1;
    }
};
edges *list_edges[100001];
int sup[100001] = {}, deep[100001] = {};
int main(){
    int n, m, u, v, w, index = -1, num = 0, weigh = 0;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &u, &v, &w);
        list_edges[i] = new edges(u, v, w);
    }
    sort(list_edges, list_edges + m, [](edges *a, edges *b)->bool{
        return a->w <= b->w;
    });
    while(num < n - 1){
        u = list_edges[++index]->u;
        v = list_edges[index]->v;
        while(sup[u]) u = sup[u];
        while(sup[v]) v = sup[v];
        if(u != v){
            ++num;
            if(deep[u] == deep[v]) ++deep[v];
            if(deep[u] > deep[v]) sup[v] = u;
            else sup[u] = v;
            weigh += list_edges[index]->w;
        }
    }
    cout << weigh;
}
