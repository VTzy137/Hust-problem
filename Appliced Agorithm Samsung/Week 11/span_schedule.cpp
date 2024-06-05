#include <bits/stdc++.h> 
using namespace std;
struct constraints{
    int i;
    constraints *n;
    constraints(int i1, constraints *n1){
        i = i1;
        n = n1;
    }
};
constraints *q[10001];
int n, m, i, j, curr_time = 0, d[10001], execute[10001], num = 0;
bool ktra(int j){
    constraints *tmp = q[j];
    while(tmp){
        if(!execute[tmp->i] || execute[tmp->i] + d[tmp->i] > curr_time)
            return false;
        tmp = tmp->n;
    }
    return true;
}

int main(){ 
    cin >> n >> m;
    for(int k = 1 ; k <= n; ++k)
        scanf("%d", &d[k]);
    for(int k = 0; k < m; ++k){
        scanf("%d%d", &i, &j);
        q[j] = new constraints(i, q[j]);
    }
    while(num < n){
        ++curr_time;
        for(int k = 1; k <= n; ++k)
            if(!execute[k] && ktra(k)){
                execute[k] = curr_time;
                ++num;
            }
    }
    for(int k = 1; k <= n; ++k)
        curr_time = max(curr_time, execute[k] + d[k]);
    cout << curr_time - 1;
}
