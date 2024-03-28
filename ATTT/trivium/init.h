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