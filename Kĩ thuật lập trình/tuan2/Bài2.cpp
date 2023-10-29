#include <stdio.h>

// Hàm hoán vị vị trí.
void rtt(int &x, int &y, int &z) {
    int temp;
    // lưu tạm biến x vào temp rồi lần lượt hoán vị
    temp = x; 
    x = y;
    y = z;
    z = temp;
}

/*
Author: Nguyễn Văn Trường, 
MSSV: 20215495,
Mã lớp: 727637.
*/
int main() {
    int x, y, z;
    // Nhập x, y, z
    scanf("%d%d%d", &x, &y, &z);
    
    printf("Before: %d, %d, %d\n", x, y, z); // In thứ tự ban đầu
    rtt(x, y, z); // Hoán vị
    printf("After: %d, %d, %d\n", x, y, z); // In thứ tự sau khi hoán vị
    
    return 0;
}