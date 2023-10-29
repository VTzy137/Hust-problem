#include <bits/stdc++.h> 

using namespace std;

int main() {
	int ktra = 1, x;
	string s;
	cin >> s;
	if(s.length() == 8 && s[2] == ':' && s[5] == ':'){
		x = (s[0] - 48) * 10 + s[1] - 48;
		if(x > 23 || x < 0)
			ktra = 0;
		x = (s[3] - 48) * 10 + s[4] - 48;
		if(x > 59 || x < 0)
			ktra = 0;
		x = (s[6] - 48) * 10 + s[7] - 48;
		if(x > 59 || x < 0)
			ktra = 0;
	}
	else
		ktra = 0;

	if(ktra == 0)
		cout << "INCORRECT";
	else
		printf("%d", 3600 * ((s[0] - 48)  * 10 + s[1] - 48) + 60 * ((s[3] - 48) * 10 + s[4] - 48) + (s[6] - 48) * 10 + s[7] - 48);
	return 0;
}

