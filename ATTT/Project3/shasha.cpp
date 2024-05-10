#include <bits/stdc++.h>
using namespace std;
int main(){
    ofstream writeFile("hash.txt", ios::binary);
    unsigned char x = 156;
    for(int i = 0; i < 1000; ++i){
        x = rand() % 258;
        writeFile << x;
    }
}