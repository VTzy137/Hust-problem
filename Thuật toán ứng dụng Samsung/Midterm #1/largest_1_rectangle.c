#include <stdio.h>
int main(){
    int n, m, x, d[1001] = {}, mx = 0;
    char a;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        int b[100] = {}, *p = b;
        for(int j = 0; j < m; ++j){
            scanf("%c ", &a);
            if(a == '1') 
                ++d[j];
            else 
                d[j] = 0;
            x = d[j];
            int st = 0;
            while(*p > x){
                st += *(p + 1);
                if(*p * st > mx) 
                    mx = *p * st;
                p -= 2;
            }
            if(*p < x){
                p += 2;
                *p = x;
                *(p + 1) = 0;  
            }
            *(p + 1) += ++st;
        }
        while(*p){
            if(*p * *(p + 1) > mx) 
                mx = *p * *(p + 1);
            *(p - 1) += *(p + 1);
            p -= 2;
        }
    }
    printf("%d", mx);
}
