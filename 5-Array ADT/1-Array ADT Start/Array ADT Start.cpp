#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array {   //bu heapte oluşturalan bir dizidir kodu karışıktır ab-vantajı ise dizi bıyutunu bizim ihtiyacımaza göre belirlenir
	int* A;
	int boyut;
	int uzunluk;
};

void Display(struct Array Arr) {
	int i;
	for (i = 0; i < Arr.uzunluk; i++)
		printf("%d -", Arr.A[i]);
}
struct Array2 {  // buda stacte olulturulan b,r dizidir ancak burada oluşturduğumuz dizi bizim daha önceden belirlediğimiz sınırlar içerisinde oluşturulur
	int A[20];
	int boyut;
	int uzunluk;
};
void Display(struct Array2 Arr) {
	int i;
	for (i = 0; i < Arr.uzunluk; i++)
		printf("%d -", Arr.A[i]);
}


int main()
{
	struct Array Arr;
	int n, i;
	printf("Dizi icin boyut girniz: ");
	cin>>Arr.boyut;
	Arr.A = (int*)malloc(Arr.boyut*sizeof(int));
	printf("Dizi icin uzunluk değeri giriniz: ");
	cin >> n;
	Arr.uzunluk = n;
	printf("\nDizi elemanlarini giriniz: \n");
	for(i = 0; i < n; i++) {
		cin>>Arr.A[i];
	}
	cout << "Heap : ";
	Display(Arr);
	cout << "\nStack: ";
	struct Array2 Arr2 = { { 1,2,3,4,5 }, 20, 5 };
	Display(Arr2);
	
	
}

