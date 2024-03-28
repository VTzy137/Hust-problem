
void encrypt(int i){
    clock_t start1 = clock();
    setReg(i);
    MyReadFile.open("testData\\" + listFiles[i]);
    MyWriteFile.open("encrypt\\" + listFiles[i]);
    
    string readLine, data;
    while(getline(MyReadFile, readLine))
        data += readLine + '\n';
    data.pop_back();

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
    setReg(i);
    MyReadFile.open("encrypt\\" + listFiles[i]);
    MyWriteFile.open("decrypt\\" + listFiles[i]);

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