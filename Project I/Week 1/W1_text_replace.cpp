#include <bits/stdc++.h> 

using namespace std;

int main() {
	string p1, p2, word;
	cin >> p1;
	cin.ignore();
	getline(cin, p2);
	while(cin >> word){
		if(word == p1)
			cout << p2;
		else
			cout << word;
		cout << " ";
	}
	return 0;
}
