#include<bits/stdc++.h>
using namespace std;
int n, m, x, c = 0, s[1000001] = {};
int main(){
	scanf("%d%d", &n, &m);
    while(n--){
		scanf("%d", &x);
		c += s[m-x];
		++s[x];
	}
	cout << c;
}
