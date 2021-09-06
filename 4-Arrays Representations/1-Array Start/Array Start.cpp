#include <iostream>

int main()
{
    int b; //-->> skaler değişken  --  4  byte yer tutar
    int array[5]; //-->>vektörel değişken --20 byte yer tutat -- adres 1. indexte başlar ve 4 er 4 er artar

    //DECLARATIONS 

    int A1[5];    //arayın statik bellekkte oluşturduğu alan garbagetir
    int A2[5] = { 1,2,3,4,5 };  //arayin static araeda oluşturduğu alan sırasıyla indexteki değerle dolar
    int A3[5] = { 1,2 }; // ilk iki alan indexteki değerlerle doldurulur geri kalan boş kısımlara 0 atanır
    int A4[5] = { 0 };   //arrayın tüm bölümlerine 0 atanır
    int A5[] = { 0,1,2,3,4 };  //arayın boyutu toplam index kadardır 

    for (int i : A2)
        printf("%d-",i);
    printf("\n%d -- %d", A2[0], &A2);
    printf("\n%d -- %d", A2[1], &A2[1]);
    printf("\n%d -- %d ", 2[A2],&2[A2]);
    printf("\n%d -- %d ", *(A2+3),&*(A2+3));

 
    printf("% d", sizeof(b));
}
