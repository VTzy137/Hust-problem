#include <bits/stdc++.h>
using namespace std;

int s[20], n;
void bsg(int i, int bi){
    s[i] = bi;
    if(i == n - 1){
        for(int j = 0; j < n; j++)
            printf("%d", s[j]);
        printf("\n");
        return;
    }
    bsg(i + 1, 0);
    bsg(i + 1, 1);
}

int main() {
    cin >> n;
    bsg(0, 0);
    bsg(0, 1);
    return 0;
}
