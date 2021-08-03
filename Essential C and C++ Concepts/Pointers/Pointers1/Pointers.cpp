#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int a = 10;  // bellekte integer bir data oluşturduk
	int* p;  // integer bir pointer belirledik
	p = &a;   // bellek tutulan datanın adrsini pointera atadık

	cout << p << "---" << &a << endl;
	cout << *p << "---" << a << endl; //her iki çıktı da aynı sonucu verir

	/// Passing Parameters
	int* p1;
	int *p2;
	p1 = (int*)malloc(5 * sizeof(int)); // c language 
	p2 = new int[5]; // c++ language -------->>>> bu şekilde heape ulaşmış oluruz 

	delete [] p2; // c++ silme işlemi
	free(p1);  // c bellketen silme işlemi  **NOT çok büyük datalarda bu işlem sakıncalıdır

	return;
}
