#include<bits/stdc++.h>
using namespace std;
int main(){	
	queue<int> s;
	string x;
	int y;
	cin >> x;
	while(x != "#"){
		if(x == "PUSH"){
			scanf("%d", &y);
			s.push(y);
		}
		else{
			if(s.empty())
				printf("NULL\n");
			else{
				printf("%d\n", s.front());
				s.pop();
			}
		}
		cin >> x;
	}
    return 0;
}
