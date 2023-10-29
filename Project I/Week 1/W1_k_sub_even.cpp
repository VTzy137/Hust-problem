#include <bits/stdc++.h> 

using namespace std;

int main() {
	int n, k, ew = 0, count = 0;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < k; ++i){
		scanf("%d", &a[i]);
		if(a[i] & 1)
			ew = 1 - ew;
	}
	if(ew == 0)
		count += 1;
	for(int i = k; i < n; ++i){
		scanf("%d", &a[i]);
		if((a[i] - a[i - k]) & 1)
			ew = 1 - ew;
		if(ew == 0)
			count += 1;
	}
	cout << count;
}
