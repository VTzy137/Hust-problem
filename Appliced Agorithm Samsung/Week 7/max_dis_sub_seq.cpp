#include<bits/stdc++.h>
using namespace std;
int s[100005];
int main(){
    int t;
    cin >> t;
    while(t--){
		int n, c, es = 0, mn = 0, pre = 0, cur = 2, x[1005] = {};
        cin >> n >> c;
		for(int i = 0; i < n; i++)
            scanf("%d", &s[i]);
        sort(s, s + n);
        for(int i = n - 1; i > 0; i--){
			s[i] -= s[i-1];
			es += s[i];
        }
		es /= --c;
		while(pre + cur != 0){
			int p = 0, k = 0, mn1 = 5000;
			x[0] = 0;
			while(++k < n){
				x[p] += s[k];
				if(x[p] > es)
					x[++p] = 0;
			}
			k = -1;
			while(++k < c)
				mn1 = min(mn1, x[k]);
			if(mn1 > mn) mn = mn1;
			pre = cur;
			if(p > c) cur = 1;
			else cur = -1;
			es += cur;
		}
		cout << mn << endl;
    }
}