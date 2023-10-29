#include<bits/stdc++.h>
using namespace std;
int s[100005];
int main(){
	int n, m, x, count = 0;
	scanf("%d%d", &n, &m);
    while(n--){
		scanf("%d", &x);
		count += s[m - x];
		++s[x];
	}
	cout << count;
}
