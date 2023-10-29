#include<iostream>

using namespace std;

int main(){
    freopen("dothi.txt", "r", stdin);
    freopen("dothitomau.dot", "w", stdout);
    int n, m, x, y, max = 1;
    cin >> n >> m;
    int s[n][n], d[n] = {}, k[n];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            s[i][j] = 0;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        s[y-1][x-1] = 1;
        s[x-1][y-1] = 1;
    }
    d[0] = 1;
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++)
            k[j] = 0;
        for(int j=0; j<n; j++){
            if(s[i][j]==1)
                k[d[j]] = 1;
        }
        int j = 1;
        while(k[j]==1){
            j++;
        }
        d[i] = j;
        if(j>max)
            max = j;
    }
    int v[max];
    for(int i=1; i<max+1; i++){
        v[i] = (rand() % 8 + 1)*100000 + (rand() % 8 + 1)*10000 + (rand() % 8 + 1)*1000 + (rand() % 8 + 1)*100 + (rand() % 8 + 1)*10 + rand() % 8 +1;
        for(int j=0; j<n; j++){
            if(d[j]==i){
                d[j]=v[i];
            }
        }
    }
    cout << "graph dothi" << endl << "{" << endl;
    for(int i=0; i<n; i++){
        cout << "  " << i+1 << " [fillcolor=\"#" << d[i] << "\", style=filled];" << endl;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(s[i][j]==1){
                cout << "  " << i+1 << " -- " << j+1 << ";" << endl;
            }
        }
    }
    cout << "}";
}