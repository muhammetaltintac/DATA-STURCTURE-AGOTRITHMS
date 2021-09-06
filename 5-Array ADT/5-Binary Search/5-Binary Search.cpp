#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[15];
    int boyut;
    int uzunluk;
    int baslangic;
};
int BinarySearch(struct Array Arr, int key) {
    int l = Arr.baslangic;
    int h = Arr.uzunluk-1;
    int m;
    while (l <= h) {
        m = (h + l) / 2;
        if (key == Arr.A[m])
            return m;
        else if (key < Arr.A[m])
            h = m - 1;
        else
            l = m + 1;

    }
    return -1;
}
int RecursiveBinarySearch(int A[], int l, int h, int key) {
    int mid=0;
    if (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return RecursiveBinarySearch(A,l, mid - 1 , key);
        else
            return RecursiveBinarySearch(A, mid+1,h, key);
    }
    return -1;
}

void Display(struct Array Arr) {
    int i;
    for (i = 0; i < Arr.uzunluk; i++) {
        printf("%d ", Arr.A[i]);
    }
}

int main()
{
    struct Array Arr = { {4,8,10,15,18,21,24,27,29,33,34,37,39,41,43},15,15 ,0 };
    printf("Aramak istediginiz degeri giriniz: ");
    int n;
    std::cin >> n;
    Display(Arr);
    printf("\n%d--->%d", n,BinarySearch(Arr, n));
    printf("\n%d--->%d",n, RecursiveBinarySearch(Arr.A,0,Arr.uzunluk,n));
}

//burası benim yazmış olduğum kod benimki ile hocanın kodu arasındaki fark benimkinde arrayde değişiklikler olurken hocanınkinde olmuyor ancak her iki kodda da sonuç aynı

/*int BinearSearch(struct Array *Arr, int key) {
    int mid;
    while (Arr->baslangic <= Arr->uzunluk) {
        mid = (Arr->uzunluk - 1 + Arr->baslangic) / 2;
        if (Arr->A[mid] == key)
            return mid;
        else if (key < Arr->A[mid])
            Arr->uzunluk = mid - 1;
        else
            Arr->baslangic = mid + 1;
    }
    return -1;
}
int RecursiveBinarySearch(struct Array* Arr, int key) {
    if (Arr->baslangic <= Arr->uzunluk) {
        int mid = (Arr->uzunluk - 1 + Arr->baslangic) / 2;
        if (key == Arr->A[mid])
            return mid;
        else if (key < mid) {
            Arr->uzunluk = mid - 1;
            return RecursiveBinarySearch(Arr, key);
        }
        else {
            Arr->baslangic = mid + 1;
            return RecursiveBinarySearch(Arr, key);
        }
    }
    return -1;
}*/