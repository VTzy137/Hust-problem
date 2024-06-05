#include <bits/stdc++.h>
using namespace std;
struct node{
    int xa, ya, xb, yb;
};
node s[1002];
bool check(node p1, node p2){
    int y1 = p1.xb - p1.xa, x1 = p1.ya - p1.yb, c1 = x1 * p1.xa + y1 * p1.ya;
    int test1 = p2.xa * x1 + p2.ya * y1 - c1, test2 = p2.xb * x1 + p2.yb * y1 - c1;
    return  test1 <=0 && test2 >=0 || test1 >=0 && test2 <= 0;
}
int main(){
    int n, count = 0;
    cin >> n;
    for(int i=0; i<n; ++i){
        scanf("%d%d%d%d", &s[i].xa, &s[i].ya, &s[i].xb, &s[i].yb);
        for(int j=0; j<i; ++j)
            if(check(s[i], s[j]) && check(s[j], s[i])) count++;
    }
    cout << count << endl;
}