#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct vocab{
    int label;
    string word, defi;
    vocab(int l, string w, string d){
        label = l;
        word = w;
        defi = d;
    }
};

struct type{
    int mark = 0;
    string name;
    vector<int> allVocab;
};

vector<type> listType;
vector<vocab> listVocab;
int p = 0;

void writeFile(){
    // Ghi toàn bộ dữ liệu từ vector lines vào file "vocab.txt"
    ofstream vocabFileOut("vocab.txt");
    if(vocabFileOut){
        for (auto & x : listVocab){
            if(x.word != ""){
                vocabFileOut << x.word << "\n";
                vocabFileOut << x.label << "\n";
                vocabFileOut << x.defi << "\n";
            }
        }
        vocabFileOut.close();
    } else{
        cout << "Error writing to vocab.txt\n";
    }

    // Ghi thông tin của category vào wordrange.txt
    ofstream wordRangeFile("wordrange.txt");
    if(wordRangeFile){
        int s = listType.size();
        for(int i = 1; i < s; ++i){
            type q = listType[i];
            if(q.mark == 1){
                wordRangeFile << i << endl;
                wordRangeFile << q.name << endl;
                for(auto & x : q.allVocab)
                    wordRangeFile << listVocab[x].word << ";";
                wordRangeFile << endl;
            }
        }
        wordRangeFile.close();
    } else{
        cout << "Error writing to wordrange.txt\n";
    }
}

int findWord(string find){
    int j = 0;
    for(j; j < listVocab.size(); j++)
        if(listVocab[j].word == find)
            return j;
    return j;
}

void addNewType(int label, string name){
    if(label >= (int) listType.size())
        listType.resize(label + 1);
    if(listType[label].mark == 1){
        cout << "This category type already created.\n";
        return;
    }
    type newType;
    newType.mark = 1;
    newType.name = name;
    listType[label] = newType;
}

void addNewWord(){
    int label;
    string word, defi;
    cout << "Enter the new word: ";
    cin.ignore();
    getline(cin, word);
    if(findWord(word) < listVocab.size()){
        cout << "This word already added in BKEncyclopedia\n";
        return;
    }
    cout << "Enter the new category number: ";
    cin >> label;
    if((label >= (int) listType.size()) || (listType[label].mark == 0)){
        string name;
        cout << "Can't find category type yet, please add new type has category " << label << ":\n";    
        cout << "Enter category " << label << " type name: ";
        cin.ignore();
        getline(cin, name);
        addNewType(label, name);
    }
    cout << "Enter the new word definition: ";
    cin.ignore();
    getline(cin, defi);
    listVocab.push_back(vocab(label, word, defi));
    listType[label].allVocab.push_back(p++);
}

void readWordRanges() {
    ifstream wordRangeFile("wordrange.txt");
    if (!wordRangeFile) {
        cout << "Cannot open wordrange.txt\n";
        return;
    }

    int label;
    string name, num, range;
    while (getline(wordRangeFile, num)) {
        stringstream ss(num);
        ss >> label;
        ss.ignore();
        getline(wordRangeFile, name);
        getline(wordRangeFile, range);
        addNewType(label, name);
    }

    wordRangeFile.close();
}

void readVocabulary() {
    ifstream vocabFile("vocab.txt");
    if (!vocabFile) {
        cout << "Cannot open vocab.txt\n";
        return;
    }

    int label;
    string word, num, defi;
    while (getline(vocabFile, word)) {
        getline(vocabFile, num);
        stringstream ss(num);
        ss >> label;
        ss.ignore();
        getline(vocabFile, defi);
        listVocab.push_back(vocab(label, word, defi));
        listType[label].allVocab.push_back(p++);
    }

    vocabFile.close();
}

void summaryAllWord(int category){
    cout << "Summary all word belong to category type " << category << ": \n";
    for(auto & x : listType[category].allVocab) {
        cout << "Word: " << listVocab[x].word;
        cout << "\ndefi: " << listVocab[x].defi << endl;
    }
}

void changeWord(string word){
    int siz = listVocab.size();
    int i = findWord(word);
    if(i < (int) listVocab.size()){
        int choose;
        cout << "Enter 0 to delete and 1 to update: ";
        cin >> choose;
        listVocab[i].word = "";
        auto q = &listType[listVocab[i].label].allVocab;
        for(int j = 0; j < (*q).size(); ++j)
            if((*q)[j] == i)
                (*q).erase((*q).begin() + j);
        if(choose == 1)
            addNewWord();
        return;
    } else {
        cout << "Can not find this word.\n";
    }
}

void changeType(int category){
    int choose, newCate;
    cout << "Enter 0 to delete and 1 to update: ";
    cin >> choose;
    if(choose == 1){
        cout << "Enter new category number: ";
        cin >> newCate;
        if(newCate >= (int) listType.size())
            listType.resize(newCate + 1);
        else if(listType[newCate].mark == 0){
            cout << "This type category already added.";
            return;
        }
        if(newCate != category){
            listType[newCate] = listType[category];
            auto allVo = listType[category].allVocab;
            for(int i = 0; i < (int) allVo.size(); ++i)
                listVocab[allVo[i]].label = newCate;
            type temp;
            listType[category] = temp;
        }
        cout << "Enter new type name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        listType[newCate].name = name;
    }
    if(choose == 0){
        auto allVo = listType[category].allVocab;
        for(int i = 0; i < (int) allVo.size(); ++i)
            listVocab[allVo[i]].word = "";
        type temp;
        listType[category]  = temp;
    }
}

int main(){
    type nT;
    listType.push_back(nT);
    cout << "Welcome to BKEncyclopedia!!!\n\n";
    cout << "1. Find a word by its name.\n";
    cout << "2. Add a new word.\n";
    cout << "3. Add a new type.\n";
    cout << "4. Summary all word belong to a type.\n";
    cout << "5. Update, delete a word.\n";
    cout << "6. Update, delete Type.\n";
    cout << "7. Exit from this program.\n";
    readWordRanges();
    readVocabulary();
    writeFile();
    int import, category, label;
    string name, find, word;
    while(true){
        cout << "\nPlease enter a number to continue: ";
        cin >> import;
        if(import == 1){
            cout << "Enter the word want to find: ";
            cin.ignore();
            getline(cin, find);
            int wi = findWord(find);
            if(wi < (int) listVocab.size()){
                cout << "Word: " << listVocab[wi].word;
                cout << "\nType label: " << listVocab[wi].label;
                cout << "\ndefi: " << listVocab[wi].defi << endl;
            } else
                cout << "Can not find this word.\n";
        } else if(import == 2){
            addNewWord();
            writeFile();
        } else if(import == 3){
            cout << "Enter the category number: ";
            cin >> label;
            cout << "Enter the type name: ";
            cin.ignore();
            getline(cin, name);
            addNewType(label, name);
            writeFile();
        } else if(import == 4){
            cout << "Enter category number want to summary: ";
            cin >> category;
            summaryAllWord(category);
        } else if(import == 5){
            cout << "Enter the word want to change: ";
            cin.ignore();
            getline(cin, word);
            changeWord(word);
            writeFile();
        } else if(import == 6){
            cout << "Enter category number want to change: ";
            cin >> category;
            changeType(category);
            writeFile();
        } else if(import == 7){
            cout << "Program exit, goodbye!\n";
            return 0;
        } else
            cout << "Invalid input! Please enter a valid number.\n";
    }
}