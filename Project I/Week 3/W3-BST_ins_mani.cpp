#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int d){
        this->data = d;
        this->left = this->right = NULL;
    }
};

void insert(node *r, int d){
    if(r->data > d){
        if(r->left == NULL){
            r->left = new node(d);
            return;
        }
        insert(r->left, d);
    }
    else if(r->data < d){
        if(r->right == NULL){
            r->right = new node(d);
            return;
        }
        insert(r->right, d);
    }
    else
        return;
}

void pre(node *r){
    if(r == NULL) return;
    cout << r->data << " ";
    pre(r->left);
    pre(r->right);
}

int main(){
    string s;
    int a;
    cin >> s;
    cin >> a;
    node *root = new node(a);
    cin >> s;
    while(s != "#"){
        cin >> a;
        insert(root, a);
        cin >> s;
    }
    pre(root);
}
