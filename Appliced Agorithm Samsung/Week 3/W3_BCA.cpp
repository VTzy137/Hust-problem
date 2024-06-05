#include <bits/stdc++.h> 

using namespace std;

#define N 50
int m, n, k, conflict[N][N], sT[N], x[N], mxl = 100;
vector<int> lT[N];

bool ktra(int teacher, int sub){
    for(int i = 0; i < sub; ++i)
        if(x[i] == teacher)
            if(conflict[i][sub] == 1)
                return false;
    return true;
}

void thu(int sub){
    if(sub > n){
        mxl = 0;
        for(int i = 0; i < m; i++)
            mxl = max(mxl, sT[i]);
        return;
    }
    for(int i = 0; i < lT[sub].size(); ++i){
        int teacher = lT[sub][i];
        if(ktra(teacher, sub)){
            x[sub] = teacher;
            if(++sT[teacher] <= mxl)
                thu(sub + 1);
            --sT[teacher];
        }
    }
}

int main(){
    int i, j;
    cin >> m >> n;
    for(i = 0; i < m; i++){
        cin >> k;
        while(k--){
            cin >> j;
            lT[j].push_back(i);
        }
    }
    cin >> k;
    while(k--){
        cin >> i >> j;
        conflict[i][j] = 1;
        conflict[j][i] = 1;
    }
    thu(1);
    if(mxl == 100)
        cout << -1;
    else
        cout << mxl;
	return 0;
}
