#include <bits/stdc++.h> 

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n], temp, mx = -1000, mn = 1000, sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &temp);
		mx = max(temp, mx);
		mn = min(temp, mn);
		sum += temp;
		a[i] = temp;
	}
	string s;
	cin >> s;
	cin >> s;
	while(s != "***"){
		if(s == "find-max")
			printf("%d\n", mx);
		else if(s == "find-min")
			printf("%d\n", mn);
		else if(s == "sum")
			printf("%d\n", sum);
		else{
			int i, j, ms = -1000;
			scanf("%d%d\n", &i, &j);
			for(--i; i < j; ++i)
				ms = max(ms, a[i]);
			printf("%d\n", ms);
		}
		cin >> s;
	}
	return 0;
}
