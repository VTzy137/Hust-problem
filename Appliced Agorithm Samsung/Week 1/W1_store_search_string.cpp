#include<bits/stdc++.h>
using namespace std;
int main(){	
    string x, y;
    set<string> s;
    cin >> x;
    while(x != "*"){
    	s.insert(x);
    	cin >> x;
	}
	cin >> x;
	while(x != "***"){
		cin >> y;
		if(x == "find")
			if(s.find(y) != s.end())
				printf("1\n");
			else
				printf("0\n");
		else
			if(s.find(y) != s.end())
				printf("0\n");
			else{
				printf("1\n");
				s.insert(y);
			}
		cin >> x;
	}
}
