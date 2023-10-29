#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a, mx = -1, curr = 0;
    cin >> n;
    while(n--){
        scanf("%d", &a);
        curr += a;
        if(curr > 0 && curr % 2 == 0 && mx < curr)
            mx = curr;
        else
            curr = 0;
    }
    cout << mx;
    return 0;
}