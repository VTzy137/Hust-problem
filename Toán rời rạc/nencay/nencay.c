#include<stdio.h>
int n,v,t;
int a[2][100000],b[100001];
int thu(int k){
    for(int i=0; i<n;i++)
        for(int j=0; j<2; j++)
            if(a[j][i]==k){
                if(j==0){v=0;t=1;}
                else{v=1;t=0;}
                b[a[t][i]]-=1;
                b[k]-=1;
                if(b[0]!=0)
                    printf("%d ",a[t][i]);
                a[v][i]=-1;
                a[t][i]=-1;
                }
}
int main(){
    scanf("%d",&n);
    for(int i=0; i<=n;i++)
        b[i]=0;
    for(int i=0; i<n;i++)
        for(int j=0; j<2;j++){
            scanf("%d",&a[j][i]);
            b[a[j][i]]+=1;}
    for(int k=1; k<=n; k++)
        if(b[k]==1){
            thu(k);
            k=1;
        }
}
