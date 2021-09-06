#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//C++
void fonk(int A[], int b) {   // iki şekilde tanımlayabilirz *A veya A[] eğer * A yaparsak sadece formal parametrede birkez * kullanmamız yerli olacaktır
    int i;                    //eğer A[] kullanırsak kodun okunabilirliği dahada çok artar tavsiye edilende budur her iki yötemde call by adrestir
    A[0] = 13;                // son olarak fonk içinde yapılan değişikler main içine de etki eder
    for (i = 0; i < b; i++) {
        cout << A[i] << endl;
    }
}

int * fonk2( int n) {      // Burada fonksiyon üzerinden bir array tanımladık ve maine yolldaık
    int* p;
    p = (int*)malloc(n * sizeof(int));
    return (p);
}

int main()
{
    int A[5] = { 0,1,2,3,4 };
    fonk(A, 5);
    cout << A[0] << endl;

    int *B;
    B = fonk2(3);
    B[0] = 12;
    B[1] = 43;
    B[2] = 21;
    for (int i = 0; i < 3; i++)
        cout << B[i]<<"-";
}
