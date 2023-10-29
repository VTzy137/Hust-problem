#include<iostream>

using namespace std;
/*
Author: Nguyễn Văn Trường, 
MSSV: 20215495,
Mã lớp 727637.
*/
struct node{
    int value = 0;
    int streak = 1;
    node *next = NULL;
};

int main(){
    // file test12.txt chua test case 4
    // freopen("test12.txt", "r", stdin);
    node *p = new node;
    p->next = new node;
    int n, temp, area = 0;
    cin >> n >> p->value;
    for(int i = 1; i < n; ++i){
        scanf("%d", &temp);
        int st = p->streak;
        while(p->value > temp){
            area = max(area, p->value * st);
            p = p->next;
            st += p->streak;
        }
        if(p->value == temp)
            p->streak = 1 + st;
        else{
            node *q = new node;
            q->value = temp;
            q->streak = st - p->streak + 1;
            q->next = p;
            p = q;
        }
    }
    area = max(area, p->value * p->streak);
    while(p->next != NULL){
        p = p->next;
        max(area, p->value * p->streak);
    }
    cout << area;
}