#include<bits/stdc++.h>
using namespace std;
int main(){
    int p = 0, s[500000] = {};
    char c;
    while(c = getchar())
        if(c == '(' || c == '[' || c == '{')
            s[++p] = c + 2;
        else if(c == s[p] || c == s[p] - 1)
                --p;
        else if(p == 0 && c == '\n'){
            cout << 1;
            return 0;
        }
        else {
            cout << 0;
            return 0;
        }
}
