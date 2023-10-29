#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, x = " ";
    getline(cin, s);
    while(s != x){
        char *end = &s[0] + s.length();
        for(char *i = &s[0]; i != end; ++i)
            if(*i > 96 && *i < 123)
                *i -= 32;
        cout << s << endl;
        s = " ";
        getline(cin, s);
    }
    return 0;
}
