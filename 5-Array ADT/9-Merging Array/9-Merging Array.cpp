#include <stdio.h>
#include <stdlib.h>

struct Array {
	int A[10];
	int uzunluk;
	int boyut;
};
void Display(struct Array Arr) {
	for (int i = 0; i < Arr.uzunluk; i++)
		printf("%d ", Arr.A[i]);
}
struct Array * Merging(struct Array* Arr1, struct Array* Arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* Arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < Arr1->uzunluk && j < Arr2->uzunluk) {
		if (Arr1->A[i] < Arr2->A[j])
			Arr3->A[k++] = Arr1->A[i++];
		else
			Arr3->A[k++] = Arr2->A[j++];
	}
	for (; i < Arr1->uzunluk; i++)  //burada k=9 i=4(i 5 te olabilir) olduğu için son indexini birleştirlen arayın son indexine kopyalar.
		Arr3->A[k++] = Arr1->A[i];
	for (; j < Arr2->uzunluk; j++)  // aynı kural burası içinde geçerli
		Arr3->A[k++] = Arr2->A[j];


	Arr3->uzunluk = Arr2->uzunluk + Arr1->uzunluk;
	Arr3->boyut = 10;
	return Arr3;
}
int main() {
	struct Array Arr1 = { {3,8,16,20,25},5,10 };
	struct Array Arr2 = { {4,10,12,22,23},5,10 };
	struct Array* Arr3;
	Arr3 = Merging(&Arr1, &Arr2);
	Display(*Arr3);

}