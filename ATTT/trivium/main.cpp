#include <bits/stdc++.h>
#include <dirent.h>

using namespace std;

#include "init.h"
#include "readFiles.h"
#include "dataProcessing.h"
#include "trivium.h"

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