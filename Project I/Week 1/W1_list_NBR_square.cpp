#include <bits/stdc++.h> 

using namespace std;

int main() {
	int n;
	cin >> n;
	n += 1;
	for(int i = 1; i < n; ++i)
		printf("%d %d\n", i, i * i);
	return 0;
}
