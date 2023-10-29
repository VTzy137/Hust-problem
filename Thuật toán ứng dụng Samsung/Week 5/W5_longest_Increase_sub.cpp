#include <bits/stdc++.h> 
using namespace std;
int main(){
    int n, x, sub = 1, s[300] = {0, 1e9};
    cin >> n;
    while(n--){
        scanf("%d", &x);
        int i = 0;
        while(x > s[++i]);
        s[i] = x;
        if(i == sub) s[++sub] = 1e9;
    }
    cout << sub - 1;
}
