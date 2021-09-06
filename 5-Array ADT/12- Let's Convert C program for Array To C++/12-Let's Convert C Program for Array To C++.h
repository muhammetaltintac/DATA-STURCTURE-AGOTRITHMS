#include <iostream>
using namespace std;

class Array {
private:
    int* A;
    int* C;
    int boyut;
    int uzunluk;
    int uzunluk2;
    void Swap(int* x, int* y);
    void Swap1(int* x, int* y);
public:
    Array() {
        boyut = 10;
        uzunluk = 0;
        uzunluk2 = 0;
        A = new int[boyut];
        C = new int[boyut];
    }
    Array(int byt) {
        boyut = byt;
        uzunluk = 0;
        uzunluk2 = 0;
        A = new int[byt];
        C = new int[byt];
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int LinearSearchTransposition(int key);
    int LinearSearchMoveToHead(int key);
    int BinarySearch(int key);
    int RecursiveBinarySearch(int A[], int l, int h, int key);
    int get(int index);
    void set(int index, int x);
    int max();
    int min();
    int sum();
    int sum2(int x);
    float avg();
    void reverse();
    void reverse2();
    void leftShift();
    void leftRotate();
    void rightShift();
    void rightRotate();
    void Insert(int x);
    bool AlgorithmIsSorted(int n);
    void NleftPright();
    Array* Merging(Array);
    Array* UnionSorted(Array);
    Array* IntensectionSorted(Array);
    Array* DiffrenceSorted(Array);
    Array* UnionUnsorted(Array);
    Array* IntensectionUnsorted(Array);
    Array* DiffrenceUnsorted(Array);
};
void Array::Display() {
    int i;
    for (i = 0; i < uzunluk; i++) {
        printf(" %d ", A[i]);
    }
}
void Array::Append(int x) {
    int i = 0;
    if (uzunluk < boyut)
        A[uzunluk++] = x;

}
void Array::Insert(int index, int x) {    //dizide deðiþiklik olacaðý için dizinin adresini göndermeliyiz
    int i;
    if (index >= 0 && index <= uzunluk) {   // index 0 dan küçük olamaz ve uzunluktan küçük olamsý gerekir
        for (i = uzunluk; i > index; i--) {
            A[i] = A[i - 1];     //burada kaydýrma iþlemi yapýlýr
        }
        A[index] = x;  //burada indise eleman eklenir
        uzunluk++;     // burada uzunluk deðeri artýrýlýr
    }
}
int Array::Delete(int index) {
    int x = A[index];    //sileceðimiz deðerii baþka bir deðiþkende tutuyoruz 
    if (index >= 0 && index < uzunluk) {
        for (int i = index; i < uzunluk - 1; i++) { // burada eleman sildiðimiz için dizi uzunluðu bir eksilecek ve döngü uzunluðun 1 adým az dönecek
            A[i] = A[i + 1];
        }
        uzunluk--;
        return x;
    }
    return 0;
}
int Array::LinearSearch(int key) {   //bu normal linear search
    int i;
    for (i = 0; i < uzunluk; i++) {
        if (key == A[i])
            return i;
    }
    return -1;
}
void Array::Swap(int* x, int* y) {   // burada basit bir swap gerçekleþtirilir dizi ðzerinde iþlme yapýlacaðýndan pointer kullanmak zorundayýz
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int Array::LinearSearchTransposition(int key) {
    int i = 0;
    for (i = 0; i < uzunluk; i++) {
        if (key == A[i] && key != A[0]) {   // burada hem key kontrolu hemde ilþk index kontrolu yapýlýr
            Swap(&A[i], &A[i - 1]);   // eðer ilk index konturolunu yapmazsak i-1 diye bir adress olmadýðýndan hata alacaðýz
            return i - 1;   // bu linear search iþlemi aramanýn hýzýný yavaþ bir þekilde hýzlanndýrýr.Kýsacasý aranma sýrasýna göre veriyi öne kaydýrýr
        }
        else if (key == A[0])
            return i + 1;
    }
    return -1;
}
void Array::Swap1(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int Array::LinearSearchMoveToHead(int key) {
    int i;
    for (i = 0; i < uzunluk; i++) {
        if (key == A[i]) {
            Swap1(&A[i], &A[0]);
            return 0;  //  bu linear searchde de zaman daha efektif kullanýlmýþ olur en son aranan ilk sýradaki ile yer deðiþtirir eðer ayný arama ust uste yapýlýrsa zaman sabit doner
        }
    }
    return -1;
}
int Array::BinarySearch(int key) {
    int l = 0;
    int h = uzunluk - 1;
    int m;
    while (l <= h) {
        m = (h + l) / 2;
        if (key == A[m])
            return m;
        else if (key < A[m])
            h = m - 1;
        else
            l = m + 1;

    }
    return -1;
}
int Array::RecursiveBinarySearch(int A[], int l, int h, int key) {
    int mid = 0;
    if (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return RecursiveBinarySearch(A, l, mid - 1, key);
        else
            return RecursiveBinarySearch(A, mid + 1, h, key);
    }
    return -1;
}
int Array::get(int index) {
    if (uzunluk > index && index >= 0)
        return A[index];
}
void Array::set(int index, int x) {
    if (uzunluk > index && index >= 0)
        A[index] = x;
}
int Array::max() {
    int max = A[0];
    for (int i = 1; i < uzunluk; i++) {
        if (max < A[i])
            max = A[i];
    }
    return max;
}
int Array::min() {
    int min = A[0];
    for (int i = 1; i < uzunluk; i++) {
        if (min > A[i])
            min = A[i];
    }
    return min;
}
int Array::sum() {
    int toplam = 0;
    for (int i = 0; i < uzunluk; i++) {
        toplam = toplam + A[i];
    }
    return toplam;
}
int Array::sum2(int x) {
    int a = x;
    if (x < 0)
        return 0;
    else
        return  sum2(a - 1) + A[a];

}
float Array::avg() {
    float toplam = 0;
    for (int i = 0; i < uzunluk; i++)
        toplam = toplam + A[i];

    return toplam / uzunluk;
}
void Array::reverse() {
    int* B;
    B = new int[boyut];
    int i, j;
    for (i = uzunluk - 1, j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    for (i = 0; i < uzunluk; i++)
        A[i] = B[i];
    delete[]B;
    B = NULL;
}
void Array::reverse2() {
    int temp;
    int i, j;
    for (i = 0, j = uzunluk - 1; i < j; i++, j--) {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
void Array::leftShift() {
    int i;
    for (i = 0; i < uzunluk - 1; i++)
    {
        A[i] = A[i + 1];
    }
}
void Array::leftRotate() {
    int i, temp;
    temp = A[0];
    for (i = 0; i < uzunluk - 1; i++)
        A[i] = A[i + 1];
    A[uzunluk - 1] = temp;
}
void Array::rightShift() {
    int i;
    for (i = uzunluk; i >= 0; i--)
        A[i] = A[i - 1];
}
void Array::rightRotate() {
    int i, temp;
    temp = A[uzunluk - 1];
    for (i = uzunluk - 1; i >= 0; i--)
        A[i + 1] = A[i];
    A[0] = temp;
}
void Array::Insert(int x) {
    int i = uzunluk - 1;
    while (A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    uzunluk++;
}
bool Array::AlgorithmIsSorted(int n) {
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}
void Array::NleftPright() {   //
    int i = 0;
    int j = uzunluk2 - 1;
    while (i < j) {
        while (A[i] < 0) { i++; };
        while (A[j] >= 0) { j--; };
        if (i < j)
            Swap(&A[i], &A[j]);
    }
}
Array* Array::Merging(Array Arr2) {
    int i, j, k;
    i = j = k = 0;
    Array* Arr3 = new Array[uzunluk + Arr2.uzunluk];
    while (i < uzunluk && j < Arr2.uzunluk) {
        if (A[i] < Arr2.A[j])
            Arr3->A[k++] = A[i++];
        else
            Arr3->A[k++] = Arr2.A[j++];
    }
    for (; i < uzunluk; i++)  //burada k=9 i=4(i 5 te olabilir) olduðu için son indexini birleþtirlen arayýn son indexine kopyalar.
        Arr3->A[k++] = A[i];
    for (; j < Arr2.uzunluk; j++)  // ayný kural burasý içinde geçerli
        Arr3->A[k++] = Arr2.A[j];


    Arr3->uzunluk = Arr2.uzunluk + uzunluk;
    Arr3->boyut = 10;
    return Arr3;
}
Array* Array::UnionSorted(Array Arr2) {
    int i, j, k;
    i = j = k = 0;
    Array* Arr3;
    Arr3 = new Array[uzunluk + Arr2.uzunluk];
    while (i < uzunluk && j < Arr2.uzunluk) {
        if (A[i] < Arr2.A[j])
            Arr3->A[k++] = A[i++];
        else if (Arr2.A[j] < A[i])
            Arr3->A[k++] = Arr2.A[j++];
        else {
            Arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < uzunluk; i++) {
        Arr3->A[k++] = A[i];
    }
    for (; j < Arr2.uzunluk; j++) {
        Arr3->A[k++] = Arr2.A[j];
    }
    Arr3->uzunluk = k;
    Arr3->boyut = 10;

    return Arr3;
}
Array* Array::IntensectionSorted(Array Arr2) {
    int i, j, k;
    i = j = k = 0;
    Array* Arr3;
    Arr3 = new Array[uzunluk + Arr2.uzunluk];
    while (i < uzunluk && j < Arr2.uzunluk) {
        if (A[i] < Arr2.A[j])
            i++;
        else if (Arr2.A[j] < A[i])
            j++;
        else {
            Arr3->A[k++] = A[i++];
            j++;
        }
    }
    Arr3->uzunluk = k;
    Arr3->boyut = 10;

    return Arr3;
}
Array* Array::DiffrenceSorted(Array Arr2) {
    int i, j, k;
    i = j = k = 0;
    Array* Arr3;
    Arr3 = new Array[uzunluk + Arr2.uzunluk];
    while (i < uzunluk && j < Arr2.uzunluk) {
        if (A[i] < Arr2.A[j])
            Arr3->A[k++] = A[i++];
        else if (Arr2.A[j] < A[i])
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
Array* Array::UnionUnsorted(Array Arr2) {
    int i, j, k;
    i = j = k = 0;
    Array* Arr3;
    Arr3 = new Array[uzunluk + Arr2.uzunluk];
    for (i = 0; i < uzunluk; i++)
        Arr3->A[k++] = A[i];
    Arr3->uzunluk = uzunluk;
    for (j = 0; j < Arr2.uzunluk; j++) {
        int sayac = 0;
        for (i = 0; i < uzunluk; i++) {
            if (Arr2.A[j] == A[i]) {
                sayac++;
            }
        }
        if (sayac == 0) {
            Arr3->A[k++] = Arr2.A[j];
            Arr3->uzunluk++;
        }
    }

    return Arr3;
}
Array* Array::IntensectionUnsorted(Array Arr2) {
    int i, j, k;
    i = j = k = 0;
    Array* Arr3;
    Arr3 = new  Array[uzunluk + Arr2.uzunluk];
    for (i = 0; i < uzunluk; i++) {
        int sayac = 0;
        for (j = 0; j < Arr2.uzunluk; j++) {
            if (A[i] == Arr2.A[j])
                sayac++;
        }
        if (sayac != 0)
            Arr3->A[k++] = A[i];
    }
    Arr3->uzunluk = k;
    Arr3->boyut = 10;
    return Arr3;
}
Array* Array::DiffrenceUnsorted(Array Arr2) {
    int i, j, k;
    i = j = k = 0;
    Array* Arr3;
    Arr3 = new Array[uzunluk + Arr2.uzunluk];
    for (i = 0; i < uzunluk; i++) {
        int sayac = 0;
        for (j = 0; j < Arr2.uzunluk; j++) {
            if (A[i] != Arr2.A[j]) {
                sayac++;
            }
        }
        if (sayac == Arr2.uzunluk)
            Arr3->A[k++] = A[i];
    }
    Arr3->uzunluk = k;
    Arr3->boyut = 10;
    return Arr3;
}
