#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int boyut;
    int uzunluk;
};
void display(struct Array Arr) {
    int i = 0;
    for (i = 0; i < Arr.uzunluk; i++)
        printf("%d ", Arr.A[i]);
}
void reverse(struct Array* Arr) {
    int* B;
    B = (int*)malloc(10 * sizeof(int));
    int i, j;
    for (i = Arr->uzunluk - 1, j = 0; i >= 0; i--, j++) {
        B[j] = Arr->A[i];
    }
    for (i = 0; i < Arr->uzunluk; i++)
        Arr->A[i] = B[i];
    free(B);
    B = NULL;
}
void reverse2(struct Array *Arr) {
    int temp;
    int i, j;
    for (i = 0, j = Arr->uzunluk - 1; i < j; i++, j--) {
        temp = Arr->A[i];
        Arr->A[i] = Arr->A[j];
        Arr->A[j] = temp;
    }
}
void leftShift(struct Array* Arr) {
    int i;
    for (i = 0; i < Arr->uzunluk-1; i++)
    {
        Arr->A[i] = Arr->A[i + 1];
    }
}
void leftRotate(struct Array* Arr) {
    int i, temp;
    temp = Arr->A[0];
    for (i = 0; i < Arr->uzunluk-1; i++)
        Arr->A[i] = Arr->A[i + 1];
    Arr->A[Arr->uzunluk-1] = temp;
}
void rightShift(struct Array* Arr) {
    int i;
    for (i = Arr->uzunluk; i >=0; i--)
        Arr->A[i] = Arr->A[i-1];
}
void rightRotate(struct Array* Arr) {
    int i, temp;
    temp = Arr->A[Arr->uzunluk-1];
    for (i = Arr->uzunluk-1; i >=0; i--)
        Arr->A[i+1] = Arr->A[i];
    Arr->A[0] = temp;
}


int main()
{
    struct Array Arr = { {1,2,3,4,5,6,7,8,9,10},10,10 };
    printf("reverse1: ");
    reverse(&Arr);
    display(Arr);
    printf("\n");
    printf("reverse2: ");
    reverse2(&Arr);
    display(Arr);
    printf("\n");
    printf("Left Rotate: ");
    leftRotate(&Arr);
    display(Arr);
    printf("\n");
    printf("Right Rotate ");
    rightRotate(&Arr);
    display(Arr);
    printf("\n");
    printf("Left Shift: ");
    leftShift(&Arr);
    display(Arr);
    printf("\n");
    printf("Right Shift: ");
    rightShift(&Arr);
    display(Arr);
    printf("\n");
    printf("Left Shift: ");
    leftShift(&Arr);
    display(Arr);
    printf("\n");
    printf("Left Shift: ");
    leftShift(&Arr);
    display(Arr);
    printf("\n");
    printf("Left Shift: ");
    leftShift(&Arr);
    display(Arr);
    printf("\n");
  /*  display(Arr);
    printf("\n");
    rightRotate(&Arr);
    display(Arr);
    printf("\n");*/
}

