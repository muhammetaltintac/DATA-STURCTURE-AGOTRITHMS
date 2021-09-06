#include <stdio.h>
#include <stdlib.h>

struct Array {
	int A[10];
	int uzunluk;
	int boyut;
};
void display(struct Array Arr) {
	for (int i = 0; i < Arr.uzunluk; i++)
		printf("%d ", Arr.A[i]);
}
struct Array* UnionUnsorted(struct Array* Arr1, struct Array* Arr2); 
struct Array* IntensectionUnsorted(struct Array* Arr1, struct Array* Arr2);
struct Array* DiffrenceUnsorted(struct Array* Arr1, struct Array* Arr2);

struct Array* UnionSorted(struct Array* Arr1, struct Array* Arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* Arr3;
	Arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i<Arr1->uzunluk && j <Arr2->uzunluk) {
		if (Arr1->A[i] < Arr2->A[j])
			Arr3->A[k++] = Arr1->A[i++];
		else if (Arr2->A[j] < Arr1->A[i])
			Arr3->A[k++] = Arr2->A[j++];
		else {
			Arr3->A[k++] = Arr1->A[i++];
			j++;
		}
	}
	
	for (; i < Arr1->uzunluk; i++) {
		Arr3->A[k++] = Arr1->A[i];
	}
	for (; j < Arr2->uzunluk; j++) {
		Arr3->A[k++] = Arr2->A[j];
	}
	Arr3->uzunluk = k;
	Arr3->boyut = 10;

	return Arr3;
}
struct Array* IntensectionSorted(struct Array* Arr1, struct Array* Arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* Arr3;
	Arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < Arr1->uzunluk && j < Arr2->uzunluk) {
		if (Arr1->A[i] < Arr2->A[j])
			i++;
		else if (Arr2->A[j] < Arr1->A[i])
			j++;
		else {
			Arr3->A[k++] = Arr1->A[i++];
			j++;
		}
	}
	Arr3->uzunluk = k;
	Arr3->boyut = 10;

	return Arr3;
}
struct Array* DiffrenceSorted(struct Array* Arr1, struct Array* Arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* Arr3;
	Arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < Arr1->uzunluk && j < Arr2->uzunluk) {
		if (Arr1->A[i] < Arr2->A[j])
			Arr3->A[k++] = Arr1->A[i++];
		else if (Arr2->A[j] < Arr1->A[i])
			j++;
		else {
			i++;
			j++;
		}
	}

	Arr3->uzunluk = k;
	Arr3->boyut = 10;

	return Arr3;
}


int main() {
	struct Array Arr1 = { {3,5,10,4,6},5,10 };
	struct Array Arr2 = { {1,4,7,2,5},5,10 };
	struct Array Arr3 = { {3,4,5,6,10},5,10 };
	struct Array Arr4 = { {2,4,5,7,12},5,10 };
	struct Array* Arr5,*Arr6,*Arr7,*Arr8,*Arr9,*Arr10;
	Arr5 = UnionUnsorted(&Arr1, &Arr2);
	display(*Arr5);
	printf("\n");
	Arr6 = UnionSorted(&Arr3, &Arr4);
	display(*Arr6);
	printf("\n");
	Arr7 = IntensectionUnsorted(&Arr1, &Arr2);
	display(*Arr7);
	printf("\n");
	Arr8 = IntensectionSorted(&Arr3, &Arr4);
	display(*Arr8);
	printf("\n");
	Arr9 = DiffrenceUnsorted(&Arr1, &Arr2);
	display(*Arr9);
	printf("\n");
	Arr10 = DiffrenceSorted(&Arr3, &Arr4);
	display(*Arr10);


}


//  Karmaşık  SIRADA OLANLARIN FONKSİYONLARI



struct Array* UnionUnsorted(struct Array* Arr1, struct Array* Arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* Arr3;
	Arr3 = (struct Array*)malloc(sizeof(struct Array));
	for (i = 0; i < Arr1->uzunluk; i++)
		Arr3->A[k++] = Arr1->A[i];
	Arr3->uzunluk = Arr1->uzunluk;
	for (j = 0; j < Arr2->uzunluk; j++) {
		int sayac = 0;
		for (i = 0; i < Arr1->uzunluk; i++) {
			if (Arr2->A[j] == Arr1->A[i]) {
				sayac++;
			}
		}
		if (sayac == 0) {
			Arr3->A[k++] = Arr2->A[j];
			Arr3->uzunluk++;
		}
	}

	return Arr3;
}
struct Array* IntensectionUnsorted(struct Array* Arr1, struct Array* Arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* Arr3;
	Arr3 = (struct Array*)malloc(sizeof(struct Array));
	for (i = 0; i < Arr1->uzunluk; i++) {
		int sayac = 0;
		for (j = 0; j < Arr2->uzunluk; j++) {
			if (Arr1->A[i] == Arr2->A[j])
				sayac++;
		}
		if (sayac != 0)
			Arr3->A[k++] = Arr1->A[i];
	}
	Arr3->uzunluk = k;
	Arr3->boyut = 10;
	return Arr3;
}
struct Array* DiffrenceUnsorted(struct Array* Arr1, struct Array* Arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array* Arr3;
	Arr3 = (struct Array*)malloc(sizeof(struct Array));
	for (i = 0; i < Arr1->uzunluk; i++) {
		int sayac = 0;
		for (j = 0; j < Arr2->uzunluk; j++) {
			if (Arr1->A[i] != Arr2->A[j]) {
				sayac++;
			}
		}
		if (sayac == Arr2->uzunluk)
			Arr3->A[k++] = Arr1->A[i];
	}
	Arr3->uzunluk = k;
	Arr3->boyut = 10;
	return Arr3;
}