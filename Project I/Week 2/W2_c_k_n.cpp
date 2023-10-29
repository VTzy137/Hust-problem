#include <bits/stdc++.h> 
using namespace std;
int main(){
	int n, k, s[1000], m = 1e9 + 7;
	cin >> k >> n;
	for(int i = 1; i <= n; i++){
		for(int j = i-1; j > 1; j--)
			s[j] = (s[j] % m + s[j-1]% m)% m;
		s[1] = i;
		s[i] = 1;
	}
	cout << s[k];
	return 0;
}
