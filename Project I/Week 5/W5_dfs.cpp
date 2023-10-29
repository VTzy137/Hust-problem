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
int n, m, i, j, kt = 1;

void dfs(int k){
    printf("%d", k);
    vi[k] = true;
    node *temp = s[k];
    while(temp != 0){
        if(!vi[temp->val]){
            printf(" ");
            dfs(temp->val);
        }
        temp = temp->next;
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
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
    while(kt){
        dfs(1);
        kt = 0;
        for(i = 1; i <= n; ++i)
            if(!vi[i]){
                printf(" %d", i);
                kt = i;
                break;
            }
    }
}