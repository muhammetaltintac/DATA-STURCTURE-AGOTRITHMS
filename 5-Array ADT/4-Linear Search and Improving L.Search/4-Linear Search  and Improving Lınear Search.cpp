#include <iostream>
#include <stdio.h>
#include <stdlib.h>
struct Array {
    int A[10];
    int boyut;
    int uzunluk;
};
int LinearSearch(struct Array Arr, int key) {   //bu normal linear search
    int i;
    for (i = 0; i < Arr.uzunluk; i++) {
        if (key == Arr.A[i])
            return i;
    }
    return -1;
}

void Swap(int *x ,int *y) {   // burada basit bir swap gerçekleştirilir dizi ğzerinde işlme yapılacağından pointer kullanmak zorundayız
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearchTransposition(struct Array* Arr, int key) {
    int i;
    for (i = 0; i < Arr->uzunluk; i++) {
        if (key == Arr->A[i] && key != Arr->A[0]) {   // burada hem key kontrolu hemde ilşk index kontrolu yapılır
            Swap(&Arr->A[i], &Arr->A[i - 1]);   // eğer ilk index konturolunu yapmazsak i-1 diye bir adress olmadığından hata alacağız
            return i - 1;   // bu linear search işlemi aramanın hızını yavaş bir şekilde hızlanndırır.Kısacası aranma sırasına göre veriyi öne kaydırır
        }
        else if (key == Arr->A[0])
            return i;
    }
    return -1;
}
void Swap1(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearchMoveToHead(struct Array* Arr, int key) {
    int i;
    for (i = 0; i < Arr->uzunluk; i++) {
        if (key == Arr->A[i]) {
            Swap1(&Arr->A[i],&Arr->A[0]);
            return 0;  //  bu linear searchde de zaman daha efektif kullanılmış olur en son aranan ilk sıradaki ile yer değiştirir eğer aynı arama ust uste yapılırsa zaman sabit doner
        } 
    }
    return -1;
}
void Display(struct Array Arr) {
    for (int i = 0; i < Arr.uzunluk; i++) {
        printf("%d-", Arr.A[i]);
    }
}

int main()
{
    struct Array Arr = { {8,5,6,7,9,1,0},10,7 };
    int n ;
    printf("Aramak istedeginiz deger: ");
    std::cin >> n;
    printf("\nNormal Linear Search: %d -->> %d\n", n,LinearSearch(Arr, n));
    Display(Arr);
    printf("\n\nLinear Search Transposition: %d --> %d\n",n, LinearSearchTransposition(&Arr, n));
    Display(Arr);;
    printf("\n\nLinear Search Move To Head: %d --> %d\n",n, LinearSearchMoveToHead(&Arr, n));
    Display(Arr);
    printf("\n\n");
}