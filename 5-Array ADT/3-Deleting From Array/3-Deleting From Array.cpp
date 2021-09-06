#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int boyut;
    int uzunluk;
};
int Delete(struct Array *Arr, int index) {
    int x = Arr->A[index];    //sileceğimiz değerii başka bir değişkende tutuyoruz 
    if (index >= 0 && index <Arr->uzunluk) {
        for (int i = index ; i < Arr->uzunluk-1; i++) { // burada eleman sildiğimiz için dizi uzunluğu bir eksilecek ve döngü uzunluğun 1 adım az dönecek
            Arr->A[i] = Arr->A[i+1];
        }
        Arr->uzunluk--;
        return x;
    }
    return 0;
}
void Display(struct Array Arr) {
    for (int i = 0; i < Arr.uzunluk ; i++) {
        printf(" %d ", Arr.A[i]);
    }
}

int main()
{
    struct Array Arr = { {1,3,5,7,9,},10,5 };
    printf("%d\n",Delete(&Arr, 4));
    Display(Arr);
    
}
