#include <bits/stdc++.h> 
using namespace std;
int main() {
    int n, a, tong = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        tong += a;
    }
    printf("%d", tong);
}
