#include <iostream>
#include <stdio.h>
using namespace std;

int fun1(int n) {
    if (n > 0) {
        return fun1(n - 1) + n;
    }
    return 0;
}
int x = 0;          // static variable burada veya aşağıdaki gibi tanımlanabilir
int fun2(int n) {
    //static int x = 0;
    if (n > 0) {
        x++;
        return fun2(n - 1) + x;
    }
    return 0;
}
int main()
{
    int a = 5;
    printf("global variables: %d", fun1(a));
    printf("\nstatic variables: %d", fun2(a));  //x=5
    printf("\nstatic variables: %d", fun2(a));  //static variables sıfırlanmazlar en son hangi işlem yapılmışsa onda kalırlar 
    printf("\nstatic variables: %d", fun2(a));  //x=15
}
