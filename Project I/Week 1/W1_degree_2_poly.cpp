#include <bits/stdc++.h> 

using namespace std;

int main() {
	float a, b, c, d;
	scanf("%f%f%f", &a, &b, &c);
	d = b * b / 4 - a * c;
	if(d < 0)
		printf("NO SOLUTION");
	else if(d == 0)
		printf("%.2f", - b / (2 * a));
	else{
		d = pow(d, 0.5);
		printf("%.2f %.2f", - (b / 2 + d) / a, (d - b / 2) / a);
	}
	return 0;
}
