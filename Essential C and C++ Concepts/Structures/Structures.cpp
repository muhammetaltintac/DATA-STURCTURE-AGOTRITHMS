#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct dikdortgen {
    int en;
    int boy;
    char x;
}nesne1;   // nesneyi burada tanımlayabiliriz birden fazla tanımlıyacaksak , ile oluşturmaya devam ederiz



int main()
{
    struct dikdortgen nesne2; // nesneyi burada tanımlayabiliriz;
    nesne1 = { 10,15,'a' };  // sınıf uyelerine bu şekilde erişebiliriz
    nesne2.boy = 14; nesne2.en = 12; nesne2.x = 's'; // sınıf uyelerine bu şekilde erişebiliriz

    printf("%d", sizeof(dikdortgen));  // data bellekte 4 ün katları şeklinde yer tutar
    

}

