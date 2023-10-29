#include <bits/stdc++.h>
using namespace std;

int n, n1, m, s[20], val = 0;
void thu(int k){
	if(k == n && val == m){
		for(int i = 0; i < n; i++)
			printf("%d ", s[i]);
		printf("\n");
		return;
	}
	for(int i = 1; i <= n1; i++)
		if(val + i <= m){
			val += i;
			s[k] = i;
			thu(k+1);
			val -= i;	
		}
		else
			return;
}

int main() {
	cin >> n >> m;
	n1 = m - n + 1;
	thu(0);
    return 0;
}
