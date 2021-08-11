#include <iostream>
using namespace std;

double e(int x, int n) {
    static double p = 1, f = 1;  // burada iki tane statik değişken tanımlıyoruz çünkü fonk içerisnde her çağırmada yeni bir yer ayrılmasını istemiyoruz var olan değişkenin sadece bir kere oluşturulması gerekiyor ve her seferinde içindeki değer güncellenmeli
    double r; //burada ki global değişken ise recursive sonucunu turmak için buradaki r değişkeni her çağrıldığında bellekte yeni bir yer açılacak ve hepsinin değeri bir birinden farklı olacak
    if (n == 0)
        return 1;
    
    r = e(x, n - 1);
    p = p * x; //burada üstü hesaplıyoruz
    f = f * n;//burada faktoriyeli hesaplıyoruz
    return r + p / f;   //bu bir head recursivedir bu yuzden bu fonkun çalışma mantığı önceki derslerde anlatıldı

    
}

int main()
{
    double result = 0;
    result = e(3, 50);
    cout << result;
    return 0;
}
