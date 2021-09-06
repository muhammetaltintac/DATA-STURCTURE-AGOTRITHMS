#include <iostream>
using namespace std;

int Fact(int n) {
    if (n < 0)  // bu önlem amaçlı faktoriyele eksi değer girilemez eğer girilirse overflow olur
        n = 0;
    if (n == 0)
        return 1;
    return Fact(n - 1) * n;
}

int main()
{
    cout << "factoriel result is : " << Fact(-10);
}
