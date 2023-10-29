#include <bits/stdc++.h> 

using namespace std;

int main() {
	int n, odd = 0, even = 0, x;
	cin >> n;
	while(n--){
		scanf("%d", &x);
		if(x & 1)
			odd += 1;
		else
			even += 1;
	}
	printf("%d %d", odd, even);
	return 0;
}
