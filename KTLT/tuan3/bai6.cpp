/*
Author: Nguyễn Văn Trường, 
MSSV: 20215495,
Mã lớp 727637.
*/
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){
    int temp;
    while(b!=0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}