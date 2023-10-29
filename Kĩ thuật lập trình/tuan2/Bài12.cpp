#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Tạo cấu trúc list để lưu value và key 
typedef struct list{
    int val;
    int key;
}list;
/*
Author: Nguyễn Văn Trường, 
MSSV: 20215495,
Mã lớp 727637.
*/
int main(){
    int key, val;
    vector<list> lkv; // Tạo vecto list

    // Nhập giá trị key và value, dừng khi kết thúc text hoặc nhập kí tự không phải số.
    while( (cin >> key) && (cin >> val) ){
        list temp;
        temp.key = key;
        temp.val = val;
        lkv.push_back(temp);
    }

    // Sắp xếp theo key và value bằng cách sử dụng hàm nặc danh.
    sort(lkv.begin(), lkv.end(), [] (list a, list b){
        if(a.val == b.val)  
            return a.key > b.key;
        else
            return a.val > b.val;
    });
    // In ra danh sách sau khi sắp xếp
    for(int i = 0; i < lkv.size(); i++){
        printf("%d %d\n", lkv[i].key, lkv[i].val);
    }
    return 0;
}