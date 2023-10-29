#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node *next;
    node(int k){
        this->key = k;
        this->next = NULL;
    }
};


node* fi(node *node, int key){
    while(node->key != -1){
        if(node->key == key)
            return node;
        node = node->next;
    }
    return node;
}

int main(){
    string s;
    int n, k, v;
    cin >> n;
    node *p = new node(-1), *begin = p;
    while(n--){
        cin >> p->key;
        p->next = new node(-1);
        p = p->next;
    }
    cin >> s;
    while(s != "#"){
        if(s == "addlast"){
            cin >> k;
            if(fi(begin, k)->key == -1){
                p->key = k;
                p->next = new node(-1);
                p = p->next;
            }
        }
        else if(s == "addfirst"){
            cin >> k;
            if(fi(begin, k)->key == -1){
                node *t = new node(k);
                t->next = begin;
                begin = t;
            }
        }
        else if(s == "addafter"){
            cin >> k >> v;
            node *t = fi(begin, v);
            if(fi(begin, k)->key == -1 && t->key != -1){
                node *t1 = new node(k);
                t1->next = t->next;
                t->next = t1;
            }
        }
        else if(s == "addbefore"){
            cin >> k >> v;
            node *t = fi(begin, v);
            if(fi(begin, k)->key == -1 && t->key != -1){
                node *t1 = new node(v);
                t1->next = t->next;
                t->next = t1;
                t->key = k;
            }
        }
        else if(s == "remove"){
            cin >> k;
            node *t = fi(begin, k);
            if(t->key != -1){
                if(t->next->key == -1)
                    p = t;
                t->key = t->next->key;
                t->next = t->next->next;
            }
        }
        else if(s == "reverse"){
            node *k = begin, *l = k->next;
            p = begin;
            while(l->next != NULL){
                node *t = l->next;
                l->next = k;
                k = l;
                l = t;
            }
            begin = k;
            p->next = new node(-1);
            p = p->next;
        }
        cin >> s;
    }
    node *t = begin;
    while(t != p){
        cout << t->key << " ";
        t = t->next;
    }
}
