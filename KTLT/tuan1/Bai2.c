//Nguyễn Văn Trường - 20215495, mã lớp 727637
#include<stdio.h>
int main(){
    int a[7] = {13, -365, 235, 47, 67, 943, 1222};
    for(int i=0; i<5; i++)
        printf("\na[%d] : %p", i, &a[i]);
    return 0;
}