#include <bits/stdc++.h>
using namespace std;
#define N 1000000
int n,m,M[30][N];
int A[N];

void preprocessing(){
    for(int j=0;(1<<j)<=m;j++){
        for(int i=0;i<n;i++)M[j][i]=-1;
    }
    for(int i=0;i<n;i++)M[0][i]=i;
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            if(A[M[j-1][i]]<A[M[j-1][i+(1<<(j-1))]])M[j][i]=M[j-1][i];
            else M[j][i]=M[j-1][i+(1<<(j-1))];
        }
    }
}

int rmq(int i,int j){
    int k=log2(j-i+1);
    int p2k=(1<<k);
    if(A[M[k][i]]<=A[M[k][j-p2k+1]]){
        return M[k][i];
    }
    else{
        return M[k][j-p2k+1];
    }
}
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
for(int i=0;i<n;i++)cin>>A[i];
preprocessing();
int res=0;
cin>>m;
for(int i=0;i<m;i++){
    int Y,Z;
    cin>>Y>>Z;
    res+=A[rmq(Y,Z)];
}
cout<<res;
return 0;
}