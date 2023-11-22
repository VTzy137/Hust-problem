#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("test.txt", "r", stdin);
    string s;
    getline(cin, s);
    long long x[100000] = {}, x1[100000] = {}, i = -1, j = 1, k = 0, len = s.length(), tmp = 0, m = 1e9+7;
    while(++i < len){
        if(s[i] > 47 && s[i] < 58){
            tmp = tmp * 10 + s[i] - 48;
        }
        else if(s[i] == '+'){
            if(!tmp){
                cout << "NOT_CORRECT";
                return 0;
            }
            if(k){
                tmp *= x1[k];
                while(--k)
                    tmp = (tmp * x1[k]) % m;
            }
            x[j++] = tmp;
            tmp = 0;
        }
        else if(s[i] == '*'){
            if(!tmp){
                cout << "NOT_CORRECT";
                return 0;
            }
            x1[++k] = tmp;
            tmp = 0;
        }
    }
    if(!tmp){
        cout << "NOT_CORRECT";
        return 0;
    }
    if(k){
        tmp *= x1[k];
        while(--k)
            tmp = (tmp * x1[k]) % m;
    }
    x[j++] = tmp;
    long long result = 0;
    while(--j){
        result = (result + x[j]) % m;
    }
    cout << result;
}