#include<stdio.h>
int convert_int(char *s){
    int num = 0;
    char *i = s - 1;
    while(*(++i) != 0)
        if(*i < 58 && *i > 47) num = num * 10 + *i - 48; 
    return num;
}
int cus_shop[1001][1001] = {}, shop[1001] = {}, t[86401] = {}, t1[86401];
int main(){
    int num_order = 0, total_reve = 0, r;
    char c[10], p[10], s[50], x[10];
    scanf("%s", c);
    while(c[0] != '#'){
        scanf("%s%d%s%s", p, &r, s, x);
        ++num_order;
        total_reve += r;
        cus_shop[convert_int(c)][convert_int(s)] += r;
        shop[convert_int(s)] += r;
        t[(x[0]*10 + x[1])*3600 + (x[3]*10 + x[4])*60 + x[6]*10 + x[7] - 1933008] += r;
        scanf("%s", c);
    }
    for(int i = 1; i < 86401; ++i){
        t[i] += t[i-1];
        t1[i] = total_reve - t[i];
    }
    scanf("%s", s);
    while(s[0] != '#'){
        if(s[7] == 'r'){
            if(s[14] == 0) printf("%d\n", total_reve);
            else{
                scanf("%s%s", s, x);
                printf("%d\n", total_reve - t[(s[0]*10 + s[1])*3600 + (s[3]*10 + s[4])*60 + s[6]*10 + s[7] - 1933009] - t1[(x[0]*10 + x[1])*3600 + (x[3]*10 + x[4])*60 + x[6]*10 + x[7] - 1933008]);
            }
        }
        else if(s[7] == 'e'){
            scanf("%s", s);
            printf("%d\n", shop[convert_int(s)]);
        }
        else if(s[7] == 'c'){
            scanf("%s%s", c, s);
            printf("%d\n", cus_shop[convert_int(c)][convert_int(s)]);
        }
        else if(s[7] == 'n') printf("%d\n", num_order);
        scanf("%s", s);
    }
    return 0;
}