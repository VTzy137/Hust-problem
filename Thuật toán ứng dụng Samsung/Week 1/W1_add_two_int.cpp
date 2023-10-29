#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long int a, b, c, d;
	scanf("%llu%llu", &a, &b);
	d = a % 10 + b % 10;
	a /= 10;
	b /= 10;
	c = a + b;
	if(d > 9)
		c += 1;
	if(c > 0)
		printf("%llu", c);
	printf("%llu", d % 10);
}