#include<bits/stdc++.h>
using namespace std;

string hexToBit(char i){
    if(i > 90) i -= 87;
    else i-= '0';
    string s = "0000";
    int p = 4;
    while(i){
        --p;
        if(i & 1) s[p] = '1';
        i >>= 1; 
    }
    return s;
}

string xoo(string x1, string x2) {
    int t = max(x1.size(), x2.size());
    string s;
    for(int i=0; i < t; ++i){
        if(x1[i] == x2[i]) s += '0';
        else s += '1';
    }
    return s;
}

string bitToHex(string x){
    string s;
    int len = x.size();
    for(int i = 0; i < len; i += 4){
        int t = 0;
        for(int j = 0; j < 3; ++j){
            t += x[i+j] - '0';
            t <<= 1;
        }
        t += x[i+3] - '0';
        if(t > 9) t += 87;
        else t += '0';
        s += t;
    }
    return s;
}

string textbit(string x){
    int len = x.size();
    string s;
    for(int i = 0; i < len; i+=8){
        int t = x[i] - '0';
        for(int j = 1; j < 8; ++j){
            t <<= 1;
            t += x[i+j] - '0';
        }
        s += t;
    }
    return s;
}

int main(){
    freopen("test.txt", "r", stdin);
    string s[11], x[11], spa, key;
    spa += hexToBit('2'); spa += hexToBit('0');
    int c[11][170] = {};
    for(int i=0; i<11; ++i){
        cin >> s[i];
        for(char j : s[i]){
            x[i] += hexToBit(j);
        }
    }

    for(int i=0; i<11; ++i){
        for(int j=i+1; j<11; ++j){
            string kq = xoo(x[i], x[j]); 
            kq = bitToHex(kq);
            for(int k = 0; k < 166; k+=2){
                if(kq[k] > '3' || (kq[k] == '0' && kq[k+1] == '0')){
                    ++c[i][k];
                    ++c[j][k];
                }
            }
        }
    }

    for(int k = 0; k < 166; k+=2){
        int i = 0;
        for(int j = 1; j < 11; ++j){
            if(c[j][k] > c[i][k]) i = j;
        }
        string tmp;
        tmp += hexToBit(s[i][k]); tmp += hexToBit(s[i][k+1]);
        key += bitToHex(xoo(tmp, spa));
    }
    string cryp = "32510ba9babebbbefd001547a810e67149caee11d945cd7fc81a05e9f85aac650e9052ba6a8cd8257bf14d13e6f0a803b54fde9e77472dbff89d71b57bddef121336cb85ccb8f3315f4b52e301d16e9f52f904";
    string key1, cryp1;
    for(int i = 0; i < 166; ++i){
        key1 += hexToBit(key[i]);
        cryp1 += hexToBit(cryp[i]);
    }
    cout << textbit(xoo(key1, cryp1));
}