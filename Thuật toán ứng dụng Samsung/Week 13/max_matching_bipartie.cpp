#include<bits/stdc++.h>
using namespace std;
int connect[10001] = {}, visited[10001] = {}, come[10001];
vector<int> s[10001];
bool findPath(int u){
    come[u] = false;
    for(int i : s[u])
        if(!connect[i] || (come[connect[i]] && findPath(connect[i]))){
            visited[u] = true;
            connect[i] = u;
            return true;
        }
    return false;
}
int main(){
    int n, m, i, j, k, number = 0;
    cin >> n >> m;
    for(i = 1; i <= n; ++i){
        scanf("%d", &j);
        while(j--){
            scanf("%d", &k);
            s[i].push_back(k);
        }
    }
    for(i = 1; i <= n; ++i){
        for(j = 1; j <= m; ++j) come[j] = true;
        if(!visited[i] && findPath(i)) number++;
    }
    cout << number;
}