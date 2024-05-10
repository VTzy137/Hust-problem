#include<bits/stdc++.h>
using namespace std;

unsigned int h0, h1, h2, h3, h4, h5, h6, h7, k[64];
vector<unsigned int> x;

int rightRotate(unsigned int n, int d) {
    return (n >> d) | (n << (32 - d)); 
} 

void init(){
    h0 = 0x6a09e667;
    h1 = 0xbb67ae85;
    h2 = 0x3c6ef372;
    h3 = 0xa54ff53a;
    h4 = 0x510e527f;
    h5 = 0x9b05688c;
    h6 = 0x1f83d9ab;
    h7 = 0x5be0cd19;

    unsigned int k1[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    for(int i = 0; i < 64; ++i){
        k[i] = k1[i];
    }
}

void readFile() {
    ifstream file("tt.txt", std::ios::binary);
    // ifstream file("birthday.mp4", std::ios::binary);
    // ofstream writeFile("bb.mp4", ios::binary);
    if (!file.is_open()) {
        std::cerr << "Không thể mở tệp.\n";
        return;
    }

    long long i = 0; 
    string s;
    while (getline(file, s)) {
        s += '\n';
        for(char byte : s) {
            // std::cout << "Byte: " << static_cast<unsigned int>(byte) << std::endl; // In ra giá trị byte (dưới dạng số nguyên)
            // unsigned int bb = byte;
            if((i & 3) == 0) x.push_back(0);
            x[i/4] = (x[i/4] << 8) + byte;
            ++i;
        }
    }
    long long n = (i << 3);
    // cout << n << " " << x.size() << endl;
    if((i & 3) == 0) x.push_back(0);
    //  cout << i << " " << x.size();
    x[i/4] = (x[i/4] << 8) + 128;
    ++i;
    cout << n << endl;
    for(i; (i % 64) != 56; ++i) {
        if((i & 3) == 0) x.push_back(0);
        x[i/4] <<= 8;
    }
    bitset<64> nn = n;
    // cout << x.size() << endl;
    x.push_back((n >> 32));
    x.push_back(n);
    bitset<32> okok = x[x.size()-2], koko = x[x.size()-1];
    // cout << okok << koko << endl;
    // cout << x[x.size()-1] << endl;
    
    // for (int c : x) {
    //     std::bitset<32> bits(c); // Chuyển ký tự thành chuỗi bit, mỗi ký tự có 8 bit
    //     cout << bits.to_string() << " "; // Ghép chuỗi bit vào chuỗi kết quả
    // }
}


void compression(unsigned int *w) {
    unsigned int a=h0, b=h1, c=h2, d=h3, e=h4, f=h5, g=h6, h=h7, s1, ch, tmp1, s0, maj, tmp2;
    for(int i = 0; i < 64; ++i) {
        s1 = (rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25));
        ch = ((e & f) ^ ((~e) & g));
        tmp1 = (h + s1 + ch + k[i] + w[i]);
        s0 = (rightRotate(a, 2) ^ rightRotate(a, 13) ^ rightRotate(a, 22));
        maj = ((a & b) ^ (a & c) ^ (b & c));
        tmp2 = s0 + maj;
        
        h = g;
        g = f;
        f = e;
        e = d + tmp1;
        d = c;
        c = b;
        b = a;
        a = tmp1 + tmp2;
    }
    // bitset<32> a1(g), a2(h);
    // cout << a1 << endl << a2 << endl;
    h0 = h0 + a;
    h1 = h1 + b;
    h2 = h2 + c;
    h3 = h3 + d;
    h4 = h4 + e;
    h5 = h5 + f;
    h6 = h6 + g;
    h7 = h7 + h;
}

void processMessage(int i) {
    unsigned int w[64];
    for(int j = 0; j < 16; ++j)
        w[j] = x[i+j];

    for(int j = 16; j < 64; ++j) {
        unsigned int s0 = w[j-15], s1 = w[j-2];
        s0 = rightRotate(s0, 7) ^ rightRotate(s0, 18) ^ (s0 >> 3);
        s1 = rightRotate(s1, 17) ^ rightRotate(s1, 19) ^ (s1 >> 10);
        w[j] = (w[j-16] + s0 + w[j-7] + s1);
    }

    // for(int j = 0; j < 64; ++j) {
    //     std::bitset<32> bits(w[j]); // Chuyển ký tự thành chuỗi bit, mỗi ký tự có 8 bit
    //     cout << bits.to_string() << " "; // Ghép chuỗi bit vào chuỗi kết quả
    // }

    compression(w);

}

int main() {

    init();

    readFile();
    
    cout << x.size() << endl;

    // for(int i = x.size()-16; i >= 0; i -= 16) {
    //     // cout << i << endl ;
    //     processMessage(i);
    // }
    
    for(int i = 0; i < x.size(); i += 16) {
        // cout << i << endl ;
        processMessage(i);
    }
    printf("%x%x%x%x%x%x%x%x\n", h0, h1, h2, h3, h4, h5, h6, h7);
    
    // for(int i : x){
        // bitset<32> j = i;
        // cout << j << " ";
        // // printf("%x ", i);
    // }
    // cout << h0;
}