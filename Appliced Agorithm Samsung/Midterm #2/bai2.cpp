#include<bits/stdc++.h>
using namespace std;
struct node{
    int i, j;
    node *next;
    node(int i1, int j1, node *n1){
        i = i1;
        j = j1;
        next = n1;
    }
};
int n, m, p, k = 1, total = 1e9;
int x[1005] = {}, c[1005][1005] = {}, r[1005] = {};
bool v[1005];
node *s[1005] = {};

bool ktra(int j){
    node *tmp = s[j];
    while(tmp){
        if(!v[tmp->i])
            return false;
        tmp = tmp->next;
    }
    return true;
}

void thu(){
    if(k > n){
        int tmp = 0;
        for(int i = 0; i <= n; ++i){
            tmp += c[r[i]][r[i+1]];
            cout << r[i] << " ";
        }
        cout << r[n+1] << "  " << tmp << endl;
        total = min(total, tmp);
        return;
    }
    for(int i = 1; i <=n; ++i){
        if(!v[i] && ktra(i)){
            v[i] = true;
            r[k++] = i;
            thu();
            --k;
            v[i] = false;
        }
    }
}

int main(){
    // freopen("test.txt", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> r[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%d", &c[i][j]);
        }
    }
    cin >> m;
    int i, j;
    while(m--){
        scanf("%d%d", &i, &j);
        s[j] = new node(i, j, s[j]);
    }
    // r[n+1] = 0;
    // thu();
    for(int i = 1; i <= n; ++i){
        if(!ktra(r[i])){
            cout << " " << -1;
            return 0;
        }
        v[r[i]] = true;
    }
    r[n+1] = r[1];
    int tmp = 0;
    for(int i = 0; i <= n; ++i){
        tmp += c[r[i]][r[i+1]];
    }
    // cout << r[n+1] << "  ";
    cout << tmp;
    // cout << total;
}