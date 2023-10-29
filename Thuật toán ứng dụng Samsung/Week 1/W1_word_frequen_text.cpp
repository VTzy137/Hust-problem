#include <bits/stdc++.h>
using namespace std;
int main() {
    string s = "", x = "";
    map<string, int> m;
    while(getline(cin, s)){
        if(s == "")
            break;
        for(auto i = s.begin(); i != s.end(); i++){
            if(*i == ' '){
                m[x] += 1;
                x = "";
            }
            else
                x += *i;
        }
    }
    auto i = m.begin();
    if(i->first == "")
        i++;
    for(i; i != m.end(); i++){
        cout << i->first;
        printf(" %d\n", i->second);
    }
}
