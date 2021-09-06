#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int boyut;
    int uzunluk;
};
void Display(struct Array Arr) {
    int i;
    for (i = 0; i < Arr.uzunluk; i++) {
        printf(" %d ", Arr.A[i]);
    }
}
void Append(struct Array* Arr, int x) {
    int i;
    if (Arr->uzunluk < Arr->boyut) 
        Arr->A[Arr->uzunluk++] = x;

}

void Insert(struct Array* Arr, int index, int x) {    //dizide değişiklik olacağı için dizinin adresini göndermeliyiz
    int i;
    if (index >= 0 && index<=Arr->uzunluk) {   // index 0 dan küçük olamaz ve uzunluktan küçük olamsı gerekir
        for (i = Arr->uzunluk; i > index; i--) {
            Arr->A[i] = Arr->A[i-1];     //burada kaydırma işlemi yapılır
        }
        Arr->A[index] = x;  //burada indise eleman eklenir
        Arr->uzunluk++;     // burada uzunluk değeri artırılır
    }
}

int main()
{
    struct Array Arr = { {1,3,5,7,9},10,5 };
    Insert(&Arr, 4, 4);
  //  Append(&Arr, 4);   yorum satırına almamızın nedeni Insertun APPEND işleminide yapıyor olması
    Display(Arr);

}
