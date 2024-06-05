#include <bits/stdc++.h>
using namespace std;
unsigned long long int a, b, ex = 1, m = 1e9 + 7, s[100], x[100], k = -1;
int main(){
	scanf("%llu%llu", &a, &b);
    s[0] = a % m;
    for(int i = 1; i < 100; i++){
        s[i] = (s[i - 1] * s[i - 1]) % m;
    }
    while(b){
        x[++k] = b % 2;
        b = (b - b % 2) / 2; 
    }
    for(int i = 0; i < 100; ++i){
        if(x[i]){
            ex = (ex * s[i]) % m;
        }
    }
    cout << ex;
}
