#include <iostream>
using namespace std;
int fact(int n) {
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}
int nCrF(int n, int r) { //burada faktoriyel yardımıyla anam babam usulu formule sadık kalarak hesaplama yapıyoruz
    int num = fact(n);
    int num1 = fact(r) * fact(n - r);
    return num / num1;
}
int NCR(int n, int r) {
    if (r == 0 || n == r)
        return 1;
    return NCR(n - 1, r - 1) + NCR(n - 1, r);  //burada ise resursive mantığını kullanarak pascal üçgeni yardımıyla bu formulü elde edip sonucu hesaplıyoruz
}
int main()
{
    cout << "FAKTORIYEL KULLANARAK: "<<nCrF(8, 2);
    cout <<"\nSADECE RECURSIVE KULLANARAK: "<< NCR(8, 2);
}

