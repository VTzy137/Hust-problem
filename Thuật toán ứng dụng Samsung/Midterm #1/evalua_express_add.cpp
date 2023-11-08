#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int a = 0, sum = 0, kt = 0;
    getline(cin, s);
    int l = s.length();
    for(int i = 0; i < l; ++i){
        if(s[i] == '+'){
            if(kt == 1){
                cout << "NOT_CORRECT";
                return 0;
            }
            kt = 1;
            sum += a;
            a = 0;
        }
        else if(s[i] > 47 && s[i] < 58){
            kt = 0;
            a = a * 10 + s[i] - 48;
        }
    }
    if(kt != 1){
        sum += a;
        cout << sum;
    }
    else
        cout << "NOT_CORRECT";
}
