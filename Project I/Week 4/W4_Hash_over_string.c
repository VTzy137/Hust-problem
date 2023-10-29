#include<stdio.h>
int main(){
    char s[200];
    int n, m, x[200] = {1};
    scanf("%d%d", &n, &m);
    for(int i = 1; i < 200; ++i)
        x[i] = (256 * x[i - 1]) % m;
    while(n--){
        scanf("%s", s);
        int h = 0;
        char *i = s - 1, *j = s - 1;
        while(*(++j) != '\0');
        --j;
        while(*(++i) != '\0')
            h += *i * x[j - i];
        printf("%d\n", h % m);
    }
}