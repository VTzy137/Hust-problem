#include <bits/stdc++.h> 

using namespace std;

int main(){
    int a[40] = {0, 1}, n;
    cin >> n;
    for(int i = 2; i < n; ++i)
        a[i] = a[i - 1] + a[i - 2];
    cout << a[n - 1];
	return 0;
}
