#include<iostream>

using namespace std;

int s[100][100], d[3][1000], kt[2][50], p=0, t=1, n, m, x, y, w, e = 0;

bool ktra(int i, int j){
    int o, p1=0, t1=1;
    kt[0][0] = i;
    while(p1<t){
        int l = kt[0][p1];
        for(int k=0; k<n; k++){
            if(s[l][k]!=0){
                o = s[l][k] + kt[1][p1];
                if(o<=w){
                    if(k==j)
                        return false;
                    kt[0][t1] = l;
                    kt[1][t1] = o;
                    t1++;
                }
            }
        }
        p1++;
    }
    return true;
}

int main(){
    freopen("rr.dot","w",stdout);
    cout << "graph dt{" << endl;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> x >> y >> w;
        cout << x << " -- " << y << "[label=\"" << w <<"\"]" << endl;
        s[x][y] = w;
        s[y][x] = w;
    }
    cin >> x >> y;
    d[0][0] = x;
    d[1][0] = y;
    d[2][0] = 0;
    cin >> x >> y >> w;
    cout << "}";
}