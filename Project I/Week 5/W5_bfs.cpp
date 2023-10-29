#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;
    node(int v, node* n){
        val = v; 
        next = n;
    }
};
node *s[10001];
bool vi[10001];
int main(){
    freopen("in.txt", "r", stdin);
    int n, m, i, j, x[10001], p = -1, k = 0, kt = 1;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d%d", &i, &j);
        if(s[i] == 0 || s[i]->val > j) s[i] = new node(j, s[i]);
        else{
            node *temp = s[i];
            while(temp->next != 0){
                if(temp->next->val > j){
                    temp->next = new node(j, temp->next);
                    break;
                }
                temp = temp->next;
            }
            if(temp->next == 0) temp->next = new node(j, temp->next);
        }
        if(s[j] == 0 || s[j]->val > i) s[j] = new node(i, s[j]);
        else{
            node *temp = s[j];
            while(temp->next != 0){
                if(temp->next->val > i){
                    temp->next = new node(i, temp->next);
                    break;
                }
                temp = temp->next;
            }
            if(temp->next == 0) temp->next = new node(i, temp->next);
        }
    }
    vi[1] = true; x[0] = 1;
    printf("1");
    while(kt){
        while(++p <= k){
            node *temp = s[x[p]];
            while(temp != 0){
                if(!vi[temp->val]){
                    printf(" %d", temp->val);
                    x[++k] = temp->val;
                    vi[temp->val] = true;
                }
                temp = temp->next;
            }

        }
        kt = 0;
        for(i = 1; i <= n; ++i)
            if(!vi[i]){
                printf(" %d", i);
                vi[i] = true;
                kt = i;
                break;
            }
        x[++k] = kt;
        --p;
    }
}