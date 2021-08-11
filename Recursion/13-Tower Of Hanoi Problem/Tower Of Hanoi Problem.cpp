#include <iostream>

void TOH(int n, int A, int B, int C) {  //buradaki a b c char da olablir
    if (n > 0) {                          
        TOH(n - 1, A, C, B);
        static int a = 0;
        a++;
        printf("%d. (%d - %d)\n",a, A, C);
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    TOH(7, 1, 2, 3);  //kodun algoritmik analizi pdf halinde klaosrun içinde vardır
}

