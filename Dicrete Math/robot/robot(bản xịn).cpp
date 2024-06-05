#include<iostream>

using namespace std;

int s[100][100] ={}, d[4][10000]={}, kt[500]={}, in[3][50], p=0, t=1, n, m, x, y, w, w1, e = 0;

int ktra(int i, int j){
    if(i==j)
        return 0;
    int o, kc, p1=0, t1=1, we[n] ={};
    kt[0] = i;
    while(p1<t1){
        for(int k=0; k<n; k++)
            if(s[kt[p1]][k]!=0){
                if((s[kt[p1]][k]+we[kt[p1]])<we[k]||we[k]==0){
                    o = s[kt[p1]][k] + we[kt[p1]];
                    if(k==j)
                        kc = o;
                    kt[t1] = k;
                    we[k] = o;
                    t1++;
                }        
            }
        p1++;
    }
    return kc;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> x >> y >> w;
        s[x][y] = w;
        s[y][x] = w;
    }
    cin >> x >> y;
    d[0][0] = x;
    d[1][0] = y;
    d[2][0] = 0;
    cin >> x >> y >> w;
    while(p<t&&e==0){
        for(int i=0; i<n; i++)
            if(s[d[0][p]][i]!=0){
                w1 = ktra(i, d[1][p]);
                if(w1>w){
                    int ktt = 0;
                    for(int j=0; j<t; j++){
                        if((i==d[0][j])&&(d[1][p]==d[1][j]))
                            ktt = 1;
                    }
                    if(ktt==0){
                        d[0][t] = i;
                        d[1][t] = d[1][p];
                        d[2][t] = p;
                        d[3][t] = w1;
                        if((i==x)&&(d[1][t]==y))
                            e = t;
                        t++;
                    }
                }
            }
        for(int i=0; i<n; i++)
            if(s[d[1][p]][i]!=0){
                w1 = ktra(i, d[0][p]);
                if(w1>w){
                    int ktt = 0;
                    for(int j=0; j<t; j++){
                        if((i==d[1][j])&&(d[0][p]==d[0][j]))
                            ktt = 1;
                    }
                    if(ktt==0){
                        d[0][t] = d[0][p];
                        d[1][t] = i;
                        d[2][t] = p;
                        d[3][t] = w1;
                        if((d[0][t]==x)&&(i==y))
                            e = t;
                        t++;
                    }
                }
            }
        p++;
    }
    
    if(p==t){
        cout << "Khong co duong di thoa man" << endl;
        return 0;
    }
    p = 0;
    while(e!=0){
        in[0][p] = d[0][e];
        in[1][p] = d[1][e];
        in[2][p] = d[3][e];
        e = d[2][e];
        p++;
    }
    cout << endl;
    cout << d[0][e] << " " << d[1][e] << "        " << ktra(d[0][e], d[1][e]) << endl;
    for(p=p-1; p>=0; p--)
        cout << in[0][p] << " " << in[1][p] << "        " << in[2][p] << endl;
}