#include <bits/stdc++.h>
using namespace std;
int n, n2 = 1, m, i, j, a[500001] = {};
int getNode(int id, int l, int r){
    if(r < i || l > j) return -1;
    if(l >= i && r <= j) return a[id];
    return max(getNode(id*2, l, (l+r)/2), getNode(id*2+1, (l+r)/2+1, r));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    while(n2 < n) n2 *= 2;
    for(i = 0; i < n; ++i){
        j = i+n2;
        cin >> a[j];
        while(j /= 2) a[j] = max(a[j*2], a[j*2+1]);
    }
    cin >> m;
    while(m--){
        string s;
        cin >> s >> i >> j;
        if(s[0] == 'g') cout << getNode(1, 1, n2) << endl;
        else if(s[0] == 'u'){
            i += n2-1;
            a[i] = j;
            while(i /= 2) a[i] = max(a[i*2], a[i*2+1]);
        }
    }
}