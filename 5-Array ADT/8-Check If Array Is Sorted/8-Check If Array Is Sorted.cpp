#include <stdio.h>
#include <stdlib.h>

struct Array {
	int A[10], C[10];
	int uzunluk;
	int uzunlukc;
};
void Swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void Insert(struct Array* Arr, int x) {
	int i = Arr->uzunluk - 1;
	while (Arr->A[i] > x) {
		Arr->A[i + 1] = Arr->A[i];
		i--;
	}
	Arr->A[i+1] = x;
	Arr->uzunluk++;
}
bool AlgorithmIsSorted(struct Array Arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (Arr.A[i] > Arr.A[i + 1])
			return false;
	}
	return true;
}
void NleftPright(struct Array* Arr) {
	int i = 0;
	int j = Arr->uzunlukc - 1;
	while (i < j) {
		while (Arr->C[i] < 0) {i++;};
		while (Arr->C[j] >= 0) { j--;};
		if (i < j) 	
			Swap(&Arr->C[i], &Arr->C[j]);
	}
}
void Display(struct Array Arr) {
	for (int i = 0; i < Arr.uzunluk; i++)
		printf("%d ", Arr.A[i]);
}
void Display1(struct Array Arr) {
	for (int i = 0; i < Arr.uzunlukc; i++)
		printf("%d ", Arr.C[i]);
}



int main() {
	struct Array Arr = { {2,4,6,8,10,12,14,16,18},{1,5,-6,8,-4,12,34,-12,-43,-7},9, 10 };
    Insert(&Arr, 5);
    Display(Arr);
    printf("\n%d \n",AlgorithmIsSorted(Arr, Arr.uzunluk));
    Display1(Arr);
	NleftPright(&Arr);
	printf("\n");
	Display1(Arr);

}