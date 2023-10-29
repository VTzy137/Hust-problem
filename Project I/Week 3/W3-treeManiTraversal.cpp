#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    vector<node*> sub;
    node(int k){ this->key = k; }
};

int kt; node *sf;
void fi(node *node, int key){
    if(kt == 1) return;
    if(node->key == key){
        sf = node;
        return;
    }
    for(int i = 0; i < node->sub.size(); ++i) fi(node->sub[i], key);
}
node* preFi(node *node, int key){
    kt = 0; sf = NULL;
    fi(node, key);
    return sf;
}

void pre(node* node){
    if(node == NULL) return;
    printf("%d ", node->key);
    for(int i = 0; i < node->sub.size(); ++i) pre(node->sub[i]);
}

void in(node* node){
    if(node == NULL) return;
    if(node->sub.size() > 0) in(node->sub[0]);
    printf("%d ", node->key);
    for(int i = 1; i < node->sub.size(); ++i) in(node->sub[i]);
}

void post(node* node){
    if(node == NULL) return;
    for(int i = 0; i < node->sub.size(); ++i) post(node->sub[i]);
    printf("%d ", node->key);
}

int main(){
    int u, v;
    string s;
    cin >> s >> u >> s;
    node *root = new node(u);
    while(s != "*"){
        if(s == "Insert"){
            cin >> u >> v;
            node *nodeV = preFi(root, v);
            if(preFi(root, u) == NULL && nodeV != NULL)
                nodeV->sub.push_back(new node(u));
            cin >> s;
            continue;
        }
        else if(s == "PreOrder") pre(root);
        else if(s == "InOrder") in(root);
        else if(s == "PostOrder") post(root);
        cout << endl;
        cin >> s;
    }
}

