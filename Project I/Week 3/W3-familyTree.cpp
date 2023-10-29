#include<bits/stdc++.h>
using namespace std;

struct node{
    string name;
    vector<node*> child;
    node(string s){this->name = s;}
};

int des;
void d(node *node){
    for(int i = 0; i < node->child.size(); ++i){
        ++des;
        d(node->child[i]);
    }
}

int gens;
void g(node *node, int gen){
    for(int i = 0; i < node->child.size(); ++i)
        g(node->child[i], gen + 1);
    if(gen > gens)
        gens = gen;
}

int main(){
    // freopen("test.txt", "r", stdin);
    std::map<std::string, node*> map;
    string s, x;
    cin >> s;
    while(s != "***"){
        cin >> x;
        node *c = map[s], *p = map[x];
        if(c == 0){
            c = new node(s);
            map[s] = c;
        }
        if(p == 0){
            p = new node(x);
            map[x] = p;
        }
        p->child.push_back(c);
        cin >> s;   
    }
    cin >> s;
    while(s != "***"){
        cin >> x;
        if(s[0] == 'd'){
            des = 0;
            d(map[x]);
            cout << des << endl;
        }
        else{
            gens = 0;
            g(map[x], 0);
            cout << gens << endl;
        }
        cin >> s;   
    }
}
