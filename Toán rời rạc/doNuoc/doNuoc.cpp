#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    int a, b, c;
    node* pre;
};

node *ds[100] = {};
int k = 1, b = 0;
int ktt[100] = {};

void kt(node *temp){    
    for(int j=0; j<k; j++)
        if(ktt[j] == 100*temp->a + 10*temp->b + temp->c)
           return;
    cout << "\"" << temp->a << "," << temp->b << "," << temp->c << "\"" << " -- \"" << temp->pre->a << "," << temp->pre->b << "," << temp->pre->c << "\";" << endl;
    ds[k] = temp;  
    ktt[k] = 100*temp->a + 10*temp->b + temp->c;
    k++;
    
}

void test(node *p){
    node *temp = new node();
    if(p->a!=0){
        if(p->b<7){
            temp = new node();
            temp->a = max(0, p->a + p->b - 7);
            temp->b = min(7, p->a + p->b);
            temp->c = p->c;
            temp->pre = p;
            kt(temp);
        }
        if(p->c<4){
            temp = new node();
            temp->a = max(0, p->a + p->c - 4);
            temp->c = min(4, p->a + p->c);
            temp->b = p->b;
            temp->pre = p;
            kt(temp);
        }
    }
    if(p->b!=0){
        if(p->a<10){
            temp = new node();
            temp->b = max(0, p->a + p->b - 10);
            temp->a = min(10, p->a + p->b);
            temp->c = p->c;
            temp->pre = p;
            kt(temp);
        }
        if(p->c<4){
            temp = new node();
            temp->b = max(0, p->b + p->c - 4);
            temp->c = min(4, p->b + p->c);
            temp->a = p->a;
            temp->pre = p;
            kt(temp);
        }
    }
    if(p->c!=0){
        if(p->a<10){
            temp = new node();
            temp->c = max(0, p->a + p->c - 10);
            temp->a = min(10, p->a + p->c);
            temp->b = p->b;
            temp->pre = p;
            kt(temp);
        };

        if(p->b<7){
            temp = new node();
            temp->c = max(0, p->b + p->c - 7);
            temp->b = min(7, p->b + p->c);
            temp->a = p->a;
            temp->pre = p;
            kt(temp);
        };
    }
    
}

int main(){
    freopen("donuoc.dot", "w", stdout);
    ktt[0] = 74;
    int i = 0;
    node *b = new node();
    b->a = 0;
    b->b = 7;
    b->c = 4;
    b->pre = NULL;
    ds[0] = b;
    node *p;
    cout << "graph dothi {" << endl;
    while(i<20){
        test(ds[i]);
        i++;
    }
    cout << "}";
}