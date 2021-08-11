#include <iostream>
using namespace std;

float el(int x, int n) {  //iterative metot
    float s =1;
    for (; n > 0; n--) {
        s = 1 + s * x / n;  
    }
    return s;
}

double el2(int x, int n) {
    double s = 1;
    int i;
    double num = 1;
    double den = 1;
    for (i = 1; i <= n; i++) {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

double e(int x, int n) {
    static double s;
    if (n == 0)
        return s; // buradali  s  e herhangi bir başlangıç değeri atamamız gerekiyor tam olarak ben de anlamdım ancak 1 atarsak sonuç başka çıkıyor
    s = 1 + x*s/ n;
    return e(x, n - 1);
}

int main()
{
   cout << e(2,4);
   cout << endl;  //ancak hoca ascending ve descendingle alakalı bir şey olduğunu söyledi sanırım
   cout << el(2, 4);
   cout << endl; 
   cout << el2(1 ,10);
}
