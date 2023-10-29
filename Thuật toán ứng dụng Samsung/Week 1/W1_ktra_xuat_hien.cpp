#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x;
	scanf("%d", &n);
	set<int> s;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		if(s.find(x) == s.end()){
			printf("0\n");
			s.insert(x);
		}
		else
			printf("1\n");
	}
	return 0;
}