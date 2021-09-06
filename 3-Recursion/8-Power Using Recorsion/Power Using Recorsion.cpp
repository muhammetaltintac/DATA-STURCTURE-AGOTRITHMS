#include <iostream>
using namespace std;
/*int pow(int m, int n) {
    if (n == 0)                 bu işlem için  9 kere çarpma yapılıyorken aşşağıdaki fonk ile 6 kere çarpma işlemi yapılıyor (bu sayısalr kuvvet 9 için geçerli)
        return 1;
    return pow(m,n-1) * m;
}*/
int pow(int m, int n) {
    if (n == 0) //buradaki 1 çok önemmli çünkü program buradaki biden başlayarak diyer fonkların değerini bulur
        return 1;
    if (n % 2 == 0)  // buada kuvvet 2 ye bolunebiliyormu ddiye baktık. eğer bolunurse kuvveti yarıya düşürüp sayıyı kendisiyle çarpıyoruz yani 2üzeri 8 yerine  4 üzeri 4 yapıyoru<
        return pow(m * m, n / 2);
    return m * pow(m * m , (n - 1) / 2); //burada ise kuvveti tek olan sayılşarın üstünü çift sayı yapıp yukarıdaki işlemi takrarlıyoruz.
}
int main()
{
    cout << pow(2, 9) << endl;
    cout << pow(7,5);
}
