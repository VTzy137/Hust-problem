#include <iostream>

using namespace std;

// Lập phương số nguyên
int cube(int x){
    return x*x*x;
}

// Lập phương số thực
double cube(double x){
	return x*x*x;	
}

/*
Author: Nguyễn Văn Trường, 
MSSV: 20215495,
Mã lớp: 727637.
*/
int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f); // nhập số nguyên và số thực
    
    // In ra giá trị lập phương số nguyên và số thực
    printf("Int: %d\n", cube(n)); 
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}