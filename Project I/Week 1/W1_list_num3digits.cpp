#include <bits/stdc++.h> 
using namespace std;
int main() { 
    int n;
    cin >> n;
    int a = 100 + (n - 100 % n);
    if(100 % n == 0)
    	a = 100;
    for(a; a < 1000; a += n){
        printf("%d ", a);
    }
}
