#include<bits/stdc++.h>
using namespace std;
struct node{
    int b, e;
    node(int b1, int e1){
        b = b1;
        e = e1;
    }
};
node *s[100001];
int main(){
    int n, a, b, curr = 0, num = 0, p = -1, k = -1;
    cin >> n;
    while(n--){
        scanf("%d%d", &a, &b);
        s[++p] = new node(a, b);
    }
    sort(s, s + ++p, [](node *a, node *b)->bool{
        return a->e < b->e;
    });
    while(++k < p){
        if(s[k]->b > curr){
            curr = s[k]->e;
            ++num;
        }
    }
    cout << num;
}
