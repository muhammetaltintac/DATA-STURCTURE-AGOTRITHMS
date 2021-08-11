#include <stdio.h>

int rSum(int n) {  //recursion kullanmak ihtiyaca göre değişir Genelde recursion yerıne loop kullanılır amamatematik veya algoritmik problemleri recursion kullanarak çözmek daha kolaydır
    if (n == 0)
        return 0;
    return rSum(n - 1) + n;
}
int lSum(int n) {   // genelde recursion yerine loop kullanmak daha efektiftir zaman olarak recursionla aynı dereceye sahip olsada space olaarakdaha efektiftir
    int i, s = 0;
    for (i = 1; i <= n; i++)
        s = s + i; 
    return s;
    
}
int Sum(int n) {     //EN EFEKTİFİ BU
    return n * (n + 1) / 2;
}

int main()
{
    int n = 5;
    printf("for %d\nrecursion: %d",n, rSum(n));
    printf("\nloop: %d", lSum(n));
    printf("\nformula: %d", Sum(n));
    
}
