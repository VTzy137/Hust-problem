

void read_directory(const string& name, vector<string>& listFiles) {
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp))) {
        listFiles.push_back(dp->d_name);
    }
    closedir(dirp);
}

