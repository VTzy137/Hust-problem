#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
    string ss;
    getline(cin, ss);
    int l = ss.length(), p = 0, ktra = 1;
    for(int i = 0; i < l; ++i)
        if(ss[i] == '(' || ss[i] == '{' || ss[i] == '[')
            s[++p] = ss[i];
        else
            if((s[p] + 1 == ss[i]) || (s[p] + 2 == ss[i]))
                --p;
            else
                ktra = 0;
    if(p > 0)
        ktra = 0;
    cout << ktra;
}
