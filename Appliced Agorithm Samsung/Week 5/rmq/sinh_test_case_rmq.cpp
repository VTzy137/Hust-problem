#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("out.txt", "w", stdout);
    int a = 1e6;
    cout << a << endl;
    for(int i = 0; i < a; ++i)
        printf("%d ",rand() % 1000 + 100);
    cout << endl << a << endl;
    for(int i = 0; i < a; ++i){
        int b = rand() % (a-5);
        printf("%d %d\n", b, rand() % (20) + b + 1);
    }
}