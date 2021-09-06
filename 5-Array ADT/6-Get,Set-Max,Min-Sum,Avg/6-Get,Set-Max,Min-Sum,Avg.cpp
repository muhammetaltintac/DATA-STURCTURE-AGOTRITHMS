#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int boyut;
    int uzunluk;
};
int get(struct Array Arr,int index) {
    if(Arr.uzunluk>index &&  index>=0)
        return Arr.A[index];
}
void set(struct Array* Arr, int index,int x) {
    if (Arr->uzunluk > index && index >= 0)
        Arr->A[index] = x;
}
int max(struct Array Arr) {
    int max = Arr.A[0];
    for (int i = 1; i < Arr.uzunluk; i++) {
        if (max < Arr.A[i])
            max = Arr.A[i];
    }
    return max;
}
int min(struct Array Arr) {
    int min = Arr.A[0];
    for (int i = 1; i < Arr.uzunluk; i++) {
        if (min > Arr.A[i])
            min = Arr.A[i];
    }
    return min;
}
int sum(struct Array Arr) {
    int toplam = 0;
    for (int i = 0; i < Arr.uzunluk; i++) {
        toplam = toplam + Arr.A[i];
    }
    return toplam;
}
int sum2(struct Array Arr, int x) {
    
    if (x < 0)
        return 0;
    else
        return  sum2(Arr, x - 1) + Arr.A[x];

}
float avg(struct Array Arr) {
    float toplam = 0;
    for(int i=0;i<Arr.uzunluk;i++)
        toplam = toplam + Arr.A[i];
    
    return toplam /Arr.uzunluk;
}

int main()
{
    struct Array Arr = { {1,4,7,18,14,25,8,56,32,20},10,10 };
    printf("get : %d\n",get(Arr, 3));
    set(&Arr, 3, 15);
    printf("set : %d\n", get(Arr, 3));
    printf("max : %d\n", max(Arr));
    printf("min : %d\n", min(Arr));
    printf("sum : %d\n", sum(Arr));
    printf("sum2 : %d\n", sum2(Arr,2));
    printf("avg : %.2f\n", avg(Arr));

    
}