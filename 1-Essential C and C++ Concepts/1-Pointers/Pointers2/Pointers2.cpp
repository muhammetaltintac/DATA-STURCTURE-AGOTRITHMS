#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct dikdortgen {
	int boy;
	float en;
	double alan;
	char x;
};

int main()
{
	int A[5] = { 0,1,2,3,4 };
	int* p;
	p = A; // dress ataması bu şekilde yapılır aksi takdirde hata alınır ornek yanlış atama p=&A 
	for (int i = 0; i < 5; i++) {
		cout << p[i] << "---"<< &p[i]<<endl;  // bu şekilde dizinin tüm elemanlarına sırası ile içerik ve adresleri ile erişiriz

	}
	int* i;
	float* f;
	double* d;
	char* c;
	struct dikdortgen* s;
	cout << sizeof(i) << endl;
	cout << sizeof(f) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(c) << endl;
	cout << sizeof(s) << endl;
	// NOT ONLINE GDB 8 BYTE YER AYIRIRKEN VS 4 BYTE AYIRDI 
   
}
