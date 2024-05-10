#include <bits/stdc++.h>
#include <dirent.h>

using namespace std;

bitset<289> reg;
vector<string> listFiles;
ifstream MyReadFile;
ofstream MyWriteFile;
unsigned long long listIV[22][2] = {}, mod = (long long)1<<40;

void init(){
	ios_base::sync_with_stdio(false);
	random_device rd;
	mt19937_64 rng(rd());
	for (int i = 0; i < 22; i++) {
		listIV[i][0] = rng() % mod;
        listIV[i][1] = rng() % mod;
	}
}
void read_directory(const string& name, vector<string>& listFiles) {
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp))) {
        listFiles.push_back(dp->d_name);
    }
    closedir(dirp);
}

template<class T>
void setBit(T &bit, long long x1, long long x2){
    bit |= x1;
    bit <<= 40;
    bit |= x2;
}

char generate(){
    char res;
    for(int i = 0; i < 8; ++i){
        res <<= 1;
        reg[195] = reg[195] ^ reg[222];
        reg[111] = reg[111] ^ reg[126];
        reg[288] = reg[0] ^ reg[45];
        res |= reg[195] ^ reg[111] ^ reg[288];
        reg >>= 1;
    }
    return res;
}

void setReg(int i){
    reg.reset();
    setBit(reg, 0xb1c4ebd708, 0x29dc05e4c3);
    reg <<= 57;
    setBit(reg, listIV[i][0], listIV[i][1]);
    reg <<= 111;
    reg[2] = reg[1] = reg[0] = 0b1;
    for(int i = 0; i < 144; ++i)
        generate();
}

void encrypt(int i){
    clock_t start1 = clock();
    setReg(i);
    MyReadFile.open("testData\\" + listFiles[i]);
    MyWriteFile.open("encrypt\\" + listFiles[i]);
    
    string readLine, data;
    while(getline(MyReadFile, readLine))
        data += readLine + '\n';
    data.pop_back();

    MyWriteFile << listIV[i][0] << " " << listIV[i][1] << '\n';

    for(int j : data){
        j ^= generate();
        MyWriteFile << j << " ";
    }

    MyReadFile.close();
    MyWriteFile.close();
    clock_t end1 = clock();
    cout << listFiles[i] << setw(18) << "(encrypt): " << end1 - start1 << "ms" << endl;
}


void decrypt(int i){
    clock_t start1 = clock();
    MyReadFile.open("encrypt\\" + listFiles[i]);
    MyWriteFile.open("decrypt\\" + listFiles[i]);

    MyReadFile >> listIV[i][0] >> listIV[i][1];
    setReg(i);
    
    int tmp;
    while(MyReadFile >> tmp){
        tmp ^= generate();
        char c = tmp;
        MyWriteFile << c;
    }
    
    MyReadFile.close();
    MyWriteFile.close();
    clock_t end1 = clock();
    cout << listFiles[i] << setw(18) << "(decrypt): " << end1 - start1 << "ms" << endl;
}

int main() {
    clock_t start = clock();
    init();
    
    read_directory(".\\testData", listFiles);
    cout << setw(18) << "Encrypt Total \t" << listFiles.size() << " files" << endl << endl;
    
    // set key 
    listIV[2][0] = 45619864848;
    listIV[2][1] = 48618946584;
    
    cout << setw(18) << "Encrypt: " << endl;
    for(int i = 2; i < listFiles.size(); i++)
        encrypt(i);
    
    cout << endl << setw(18) << "Decrypt: " << endl;
    for(int i = 2; i < listFiles.size(); i++)
        decrypt(i);
    
    clock_t endd = clock();
    cout << endl << setw(18) << "Total:  \t" << endd-start << "ms";
}