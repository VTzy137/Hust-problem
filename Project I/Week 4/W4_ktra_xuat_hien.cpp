#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x;
	set<int> s;
	scanf("%d", &n);
    while(n--){
		scanf("%d", &x);
		if(s.find(x) == s.end()){
			printf("0\n");
			s.insert(x);
		}
		else
			printf("1\n");
	}
}
