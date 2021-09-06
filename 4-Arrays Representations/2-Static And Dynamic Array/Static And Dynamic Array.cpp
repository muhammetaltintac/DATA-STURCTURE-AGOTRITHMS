#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int staticArray[5];  //statc areada oluşturulur yeniden boyutlandırılamaz 
     //  int n;
     // cin >> n;   
     //  int staticArray2[n];   -->> bu kullanım hata verir
     // int* pp;
     //  pp = new int[n];         -->> ancak burada hata almayız
    int* p;
    p = new int[5];  //heapte oluşturulur ancak direk erişim olamaz buyuzden pointer kullanarak erişebliriz
    int *p1 = (int *) malloc(5 * sizeof(int));// c language de dinamik dizi
    p[0] = 5;
    p1[1] = 3;
    printf("%d  -  %d", p[0], p1[1]);
    printf("\n%d  -  %d", p[3], p1[4]);   //garbage 
    // .....
    // .....
    // .....    buralrada kod olduğunu varsayalıum
    // .....
    // .....
    delete[]p;  //dinamik arraylare işimizz bitince silmemiz gerekir çünkü bellekte şişmeye neden olabilir  // c++ language
    free(p1);  //c language
}

