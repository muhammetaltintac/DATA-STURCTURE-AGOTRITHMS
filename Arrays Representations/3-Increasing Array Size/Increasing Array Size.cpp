#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int* p, * q;
    p = (int*)malloc(5 * sizeof(int));   //burada dizimizi boyutlandırıyoruz
    p[0] = 1; p[1] = 2; p[2] = 5; p[3] = 9; p[4] = 10;   //daha sonra indeğlere değer atıyoruz
    for (int i=0;i<5;i++)
        printf("%d - ", p[i]);
    q = (int*)malloc(10 * sizeof(int));  //ardından ihtiyacımız olan yeni boyuta göre yeni bir dizi olüşturuyoruz
    for (int i = 0; i < 5; i++)
        q[i] = p[i];    //küçük boyutlu dizinin elemanlarını bu diziye aktarıyoruz
        cout << endl;
    for (int i = 0; i < 10; i++)
        printf("%d - ", q[i]);
    free(p);  //ardında küçük boyutlu dizimizi bellekten temizliyoruz   not pointerı silmiyoruz
    p = q;  //pointerımıaı yeni dizimizin adresini atıyoruz
    q = NULL;  //en sonunda da diğer pointerın boşluğu işaret etmsini sağlıyoruz
    cout << endl;
    for (int i = 0; i < 10; i++)
        printf("%d - ", p[i]);


}
