#include<bits/stdc++.h>
using namespace std;
struct node{
    int d, p;
    node(int d1, int p1){
        d = d1;
        p = p1;
    }
};
node *s[100001];
int x[100001] = {};
int main(){
    int n, d, p, k = -1, mx, sum = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &d, &p);
        s[++k] = new node(d, p);
    }
    sort(s, s + ++k, [](node *a, node *b)->bool{
        return a->p >= b->p;
    });
    for(int i = 0; i < k; ++i){
        int d = s[i]->d + 1;
        while(x[--d]);
        if(d != 0){
            x[d] = s[i]->p;
            sum += s[i]->p;
        }
    }
    cout << sum;
}
