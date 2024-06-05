//Day la cau B:
#include<iostream>

using namespace std;

string s[5757];
int dem = 0, eq = 0, lk[5757][5758] = {}, pb[5757];

void equ(string sj, int i, int j){
    for(int k=1; k<5; k++)
        for(int l=0; l<5; l++)
            if(s[i][k]==sj[l]){
                eq++;
                sj[l] = 0;
                break;
            }
    if(eq>3){
        dem++;
        lk[i][j] = 1;
    }
    eq = 0;
}

int main(){
    string a, b;
    int a1 = 5758, b1 = 5758, sd = 0;
    cout << "Nhap 2 tu bat dau va ket thuc: ";
    cin >> a >> b;
    freopen("sgb-words.txt", "r", stdin);
    cin >> s[dem];
    dem++;
    while(s[dem-1] != "pupal"){
        cin >> s[dem];
        dem++;
    }
    dem = 0;
    for(int i=0; i<5757; i++){
        for(int j=0; j<5757; j++)
            equ(s[j], i, j);    
    }
    cout << "So thanh phan lien thong la: " << dem << endl;
    for(int i=0; i<5757; i++){
        if(s[i]==a)
            a1 = i;
        if(s[i]==b)
            b1 = i;
    }
    if(a1==5758||b1==5758){
        if(a1==5758)
            cout<< "khong co tu \"" << a << "\" trong danh sach" << endl;
        if(b1==5758)
            cout<< " khong co tu \"" << b << "\" trong danh sach";
        return 0;
    }
    dem = 1;
    eq = 0;
    pb[0] = a1;
    while(sd==0){
        for(int i=0; i<5757; i++){
            if(lk[pb[eq]][i]==1){
                if(lk[i][5757]==0){
                    lk[i][5757] = pb[eq];
                    pb[dem] = i;
                    dem++;
                    if(i==b1){
                        sd = 1;
                    }
                }
            }
        }
        eq++;
        if(eq==dem){
            cout << "(c) Khong co duong di giua 2 tu nay";
            return 0;
        }
    }
    eq = b1;
    lk[a1][5757] = 0;
    cout << "(c) ";
    while(lk[eq][5757]!=0){
        cout << s[eq] << " <- ";
        eq = lk[eq][5757];
    }
    cout << s[eq];
}