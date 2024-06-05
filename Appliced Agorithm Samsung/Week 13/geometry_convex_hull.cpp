#include<bits/stdc++.h>
using namespace std;
int n, xmax[2005], xmin[2005], smax[10001] = {}, smin[10001] = {}, pmax = 0, pmin = 0;
bool exist[2005] = {};
void input(){
    cin >> n;
    while(n--){
        int x, y;
        scanf("%d%d", &x, &y);
        y += 1000;
        if(exist[y]){
            xmax[y] = max(xmax[y], x);
            xmin[y] = min(xmin[y], x);
        }
        else{
            exist[y] = true;
            xmax[y] = xmin[y] = x;
        }
    }
}
void findmin(){
    int kt = 0, y = 0;
    for(y; y < 2002; ++y){
        if(exist[y]){
            smin[pmin++] = y;
            if(++kt > 1) break;
        }
    }
    for(++y; y < 2002; ++y){
        if(exist[y]){
            while(--pmin){
                int x1 = xmin[smin[pmin]] - xmin[smin[pmin-1]], y1 = smin[pmin] - smin[pmin-1];
                int x2 = xmin[y] - xmin[smin[pmin-1]], y2 = y - smin[pmin-1];
                if(x2*y1 > x1*y2) break;
            }
            smin[++pmin] = y;
            ++pmin;
        }
    }
}
void findmax(){
    int kt = 0, y = 0;
    for(y; y < 2002; ++y){
        if(exist[y]){
            smax[pmax++] = y;
            if(++kt > 1) break;
        }
    }
    for(++y; y < 2002; ++y){
        if(exist[y]){
            while(--pmax){
                int x1 = xmax[smax[pmax]] - xmax[smax[pmax-1]], y1 = smax[pmax] - smax[pmax-1];
                int x2 = xmax[y] - xmax[smax[pmax-1]], y2 = y - smax[pmax-1];
                if(x2*y1 < x1*y2) break;
            }
            smax[++pmax] = y;
            ++pmax;
        }
    }
}
int main(){
    input();
    findmin();
    findmax();
    if(smin[pmin-1] == smax[pmax-1] && xmin[smin[pmin-1]] == xmax[smax[pmax-1]])
        --pmin;
    if(smin[0] == smax[0] && xmin[smin[0]] == xmax[smax[0]]){
        --pmin;
        smin[0] = smin[pmin];
    }
    cout << pmin + pmax << endl;
    for(int i=0; i<pmax;++i)
        cout << xmax[smax[i]] << " " << smax[i] - 1000 << endl;
    for(int i=0; i<pmin;++i)
        cout << xmin[smin[i]] << " " << smin[i] - 1000 << endl;
}
