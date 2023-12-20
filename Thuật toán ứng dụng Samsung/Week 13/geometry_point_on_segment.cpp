#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, xa, ya, xb, yb, xc, yc;
    cin >> n;
    while(n--){
        scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
        int ybc = xc-xb, xbc = -yc+yb, c = -(xbc*xb + ybc*yb);
        if(!(xa * xbc + ya * ybc + c) && (xa-xb)*(xa-xc) <= 0 && (ya-yb)*(ya-yc) <= 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
