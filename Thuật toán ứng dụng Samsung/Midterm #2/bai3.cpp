#include<bits/stdc++.h>
using namespace std;
int n, m, k = 1, sum = 0, c = 0, a[105] = {}, x[105] = {};

void thu(){
    if(sum == m){
        // for(int i = 1; i <= n; ++i){
        //     // cout << x[i] << " ";
        //     x[i] = 0;
        // }
        // cout << endl;
        ++c;
        return;
    }
    if(k > n){
        return;
    }
    int tmp = 0, tmpsum = sum;
    ++k;
    thu();
    while(sum + a[k-1] <= m){
        ++tmp;
        sum += a[k-1];
        x[k-1] = tmp;
        thu();
    }
    --k;
    sum = tmpsum;
}

int main(){
    // freopen("test.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    thu();
    cout << c;    
}