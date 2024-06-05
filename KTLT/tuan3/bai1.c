/*
Author: Nguyễn Văn Trường, 
MSSV: 20215495,
Mã lớp 727637.
*/
int lucas(int n) {
    if(n==0)
        return 2;
    if(n==1)
        return 1;
    return lucas(n-1) + lucas(n-2);
}