#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> d;
    string s, text;
    int e, mx, mn;
    cin >> s;
    while(s != "#"){
        if(s == "PUSH"){
            scanf("%d", &e);
            d.push(e);
        }
        else{
            mn = 1;
            mx = d.top();
            while(mx > 0){
                mn = mn * 10 + mx % 10;
                mx /= 10;
            }
            while(mn > 1){
                text += mn % 10 + 48;
                mn /= 10;
            }
            text += 10;
            d.pop();
        }
        cin >> s;
    }
    text[text.length() - 1] = 0;
    cout << text;
}
