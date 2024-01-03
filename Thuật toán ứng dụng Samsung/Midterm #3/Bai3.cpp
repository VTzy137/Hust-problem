#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, c = 0;
    scanf("%d", &n);
    while(n % 5 != 0){
        n += 2;
        ++c;
    }
    printf("%d", c + n/5);
}