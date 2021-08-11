#include <iostream>
#include <stdio.h>

void funB(int n);  //burada b fonksiyonun prototipini yazmak zorundayız çünkü biz daha b donkunu tanımlamadan a fonku içinde kullanacağımızdan compiler bize hata verecek

void funA(int n) {
    if (n > 0) {
        printf("%d-", n);
        funB(n - 1);
    }
}
void funB(int n) {
    if (n > 0) {
        printf("%d-", n);
        funA(n / 2);
    }
}

int main()
{
    funA(20);
}
