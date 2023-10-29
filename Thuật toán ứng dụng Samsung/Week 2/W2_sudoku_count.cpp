#include <bits/stdc++.h>
using namespace std;

int x[9][9]= {}, n[9][10]= {}, d[9][10]= {}, o[3][3][10]= {}, co = 0;
bool ktra(int val, int i, int j){
	if(n[i][val] == 0 && d[j][val] == 0 && o[i/3][j/3][val] == 0){
		return true;
	}
	else
		return false;
}

void thu(int k){
	if(k == 79){
		co += 1;
		return;
	}
	int i = k / 9, j = k % 9;
	if(x[i][j] == 0){
		thu(k+1);
		return;
	}
	for(int val = 1; val < 10; val++){
		if(ktra(val, i, j)){
			n[i][val] = 1;
			d[j][val] = 1;
			o[i/3][j/3][val] = 1;
			thu(k+1);
			n[i][val] = 0;
			d[j][val] = 0;
			o[i/3][j/3][val] = 0;
		}
	}
}

int main() {
	int a;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++){
			scanf("%d", &a);
			n[i][a] = 1;
			d[j][a] = 1;
			o[i/3][j/3][a] = 1;
			if(a == 0)
				x[i][j] = 1;
		}
	thu(0);
	cout << co;
	return 0;
}
