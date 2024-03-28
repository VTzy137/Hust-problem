
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