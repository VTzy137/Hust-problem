#include <bits/stdc++.h> 

using namespace std;

int main() {
	int ktra = 1, x;
	string s;
	cin >> s;
	if(s.length() == 10 && s[4] == '-' && s[7] == '-'){
		x = (s[5] - 48) * 10 + s[6] - 48;
		if(x > 12 || x < 1)
			ktra = 0;
		x = (s[8] - 48) * 10 + s[9] - 48;
		if(x > 31 || x < 1)
			ktra = 0;
	}
	else
		ktra = 0;

	if(ktra == 0)
		cout << "INCORRECT";
	else{
		for(int i = 0; i < 4; i++)
			printf("%c", s[i]);
		printf(" ");
		if(s[5] != 48)
			printf("%c", s[5]);
		printf("%c", s[6]);
		printf(" ");
		if(s[8] != 48)
			printf("%c", s[8]);
		printf("%c", s[9]);
	}
	return 0;
}
