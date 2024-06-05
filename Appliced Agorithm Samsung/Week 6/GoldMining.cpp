#include <bits/stdc++.h>
using namespace std;
int a[1000002] = {}, s[1000002] = {}, x[1000001] = {};
int main(){ 
    ios::sync_with_stdio(false); 
    cin.tie(0);
    string ss;
    int n, L1, L2, mx = 0, N = 1e6, *p = a + 1;
    cin >> n >> L1 >> L2;
    getline(cin, ss);
    getline(cin, ss);
    char *ce = &ss[0] + ss.length();
    for(char *c = &ss[0]; c != ce; ++c)
        if(*c < 48){
            if(*p != 0)
                ++p;
        }
        else
            *p = *p * 10 + *c - 48;
    for(int i = 1; i <= L1; ++i)
        s[i] = a[i];
    for(int i = L1 + 1; i <= L2 + 1; ++i){
        mx = max(s[i - L1], mx);
        ++x[s[i - L1]];
        s[i] = mx + a[i];
    }
    for(int i = L2 + 1; i <= n; ++i){
        s[i] = mx + a[i];
        ++x[s[i + 1 - L1] % N];
        --x[s[i - L2] % N];
        if(s[i + 1 - L1] > mx)
            mx = s[i - L1 + 1];
        while(!x[mx % N])
            --mx;
    }
    for(int i = n - L1; i <= n; ++i)
        mx = max(mx, s[i]);
    cout << mx;
}