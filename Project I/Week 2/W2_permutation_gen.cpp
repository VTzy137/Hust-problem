#include <bits/stdc++.h>

using namespace std;

int n, s[20], t[20]= {};

void thu(int k){
	if(k == n){
		for(int i = 0; i < n; i++)
			printf("%d ", s[i]);
		printf("\n");
		return;
	}
	for(int i = 1; i <= n; i++)
		if(t[i] == 0){
			t[i] = 1;
			s[k] = i;
			thu(k+1);
			t[i] = 0;	
		}
}

int main() {
	cin >> n;
	thu(0);
    return 0;
}
