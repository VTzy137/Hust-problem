#include<bits/stdc++.h>
using namespace std;
int convert_int(string s){
    int num = 0, j = s.length();
    for(int i = 0; i < j; ++i)
        if(s[i] < 58 && s[i] > 47) num = num * 10 + s[i] - 48; 
    return num;
}
int cus_shop[1001][1001] = {}, t[86401] = {}, t1[86401];
map<string, int> m;
int main(){
    // freopen("inputEcommerce.txt", "r", stdin);
    // freopen("outputEcommerce.txt", "w", stdout);
    int num_order = 0, total_reve = 0, r;
    string c, p, s, x;
    cin >> c;
    while(c != "#"){
        cin >> p >> r >> s >> x;
        ++num_order;
        total_reve += r;
        cus_shop[convert_int(c)][convert_int(s)] += r;
        m[s] += r;
        t[(x[0]*10 + x[1])*3600 + (x[3]*10 + x[4])*60 + x[6]*10 + x[7] - 1933008] += r;
        cin >> c;
    }
    for(int i = 1; i < 86401; ++i){
        t[i] += t[i-1];
        t1[i] = total_reve - t[i];
    }

    cin >> s;
    while(s != "#"){
        if(s == "?total_revenue_in_period"){
            cin >> s >> x;
            printf("%d\n", total_reve - t[(s[0]*10 + s[1])*3600 + (s[3]*10 + s[4])*60 + s[6]*10 + s[7] - 1933009] - t1[(x[0]*10 + x[1])*3600 + (x[3]*10 + x[4])*60 + x[6]*10 + x[7] - 1933008]);
        }
        else if(s == "?revenue_of_shop"){
            cin >> s;
            printf("%d\n", m[s]);
        }
        else if(s == "?total_consume_of_customer_shop"){
            cin >> c >> s;
            printf("%d\n", cus_shop[convert_int(c)][convert_int(s)]);
        }
        else if(s == "?total_number_orders") printf("%d\n", num_order);
        else if(s == "?total_revenue") printf("%d\n", total_reve);
        cin >> s;
    }
}