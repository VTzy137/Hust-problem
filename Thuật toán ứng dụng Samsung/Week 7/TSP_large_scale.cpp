#include <bits/stdc++.h>
using namespace std;
struct edges{
    int i, j, c = 0;
    edges(int i1, int j1, int c1){
        i = i1;
        j = j1; 
        c = c1;
    }
};
edges *s[500001];
int pa[1001]= {}, deep[1001] = {};

int main(){
    int n, p = -1, k, c = 1, x[1001] = {}, x1[1001] = {};
    cin >> n;
    if(n > 100){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){ 
                int tmp;
                scanf("%d", &tmp);
                if(i < j)
                    s[++p] = new edges(i, j, tmp);
            }
        }
        sort(s, s + ++p, [](edges *a, edges *b)->bool{
            return a->c < b->c;
        });
        k = -1;
        while(c < n){
            int i = s[++k]->i, j = s[k]->j, u = i, v = j, tmp = c;
            while(pa[u]) u = pa[u];
            while(pa[v]) v = pa[v];
            if(u != v){
                if(!x[i]){
                    if(!x[j]){
                        x[i] = j;
                        x[j] = i;
                        ++c;
                    }
                    else if(!x1[j]){
                        x[i] = j;
                        x1[j] = i;
                        ++c;
                    }
                }
                else if(!x1[i]){
                    if(!x[j]){
                        x1[i] = j;
                        x[j] = i;
                        ++c;
                    }
                    else if(!x1[j]){
                        x1[i] = j;
                        x1[j] = i;
                        ++c;
                    }
                }
                if(c > tmp){
                    if(deep[u] < deep[v]){
                        pa[u] = v;
                    }
                    else{
                        pa[v] = u;
                        deep[u] = max(deep[u], deep[v] + 1);
                    }
                }
            }
        }
        int u = 0, v = 0;
        for(int i = 1; i <= n; ++i){
            if(!x1[i]){
                if(!u)
                    u = i;
                else
                    v = i;
            }
        }
        x1[v] = u;
        x1[u] = v;
        cout << n << endl << 1;
        int tmp = 1, tmp1 = x[1];
        while(tmp1 != 1){
            cout << " " << tmp1;
            if(x[tmp1] != tmp){
                tmp = tmp1;
                tmp1 = x[tmp1];
            }
            else{
                tmp = tmp1;
                tmp1 = x1[tmp1];
            }
        }
    }
    else{
        vector<vector<int>> distance(n, vector<int>(n));
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &distance[i][j]);
            }
        }
        vector<int> result;
        int current = 0;
        result.push_back(current + 1);
        visited[current] = 1;

        for (int i = 0; i < n - 1; i++) {
            int next = -1;
            int min_distance = INT_MAX;

            for (int j = 0; j < n; j++) {
                if (!visited[j] && distance[current][j] < min_distance) {
                    min_distance = distance[current][j];
                    next = j;
                }
            }
            if (next == -1) {
                break;
            }
            result.push_back(next + 1);
            visited[next] = 1;
            current = next;
        }

        cout << n << endl;
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
    }
}
