#include <bits/stdc++.h>
using namespace std;
/*
Author: Nguyễn Văn Trường, 
MSSV: 20215495,
Mã lớp 727637.
*/
int main(){
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}