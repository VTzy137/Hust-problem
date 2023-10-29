// O(n * (k2 - k1))
#include <bits/stdc++.h>
using namespace std;
int total[1005] = {}, n, k1, k2, m = 1e9 + 7;
int main(){
    cin >> n >> k1 >> k2;
    ++k1; ++k2;
    for(int i = k1; i <= k2; ++i)
        total[i] = 1;
    for(int i = k2 + 1; i <= n + 1; ++i)
        for(int j = k1; j <= k2; ++j)
            total[i] = (total[i] + total[i-j]) % m;
    cout << total[n - 1] + 2 * total[n] + total[n + 1];
}
