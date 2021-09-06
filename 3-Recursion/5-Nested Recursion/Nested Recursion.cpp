#include <iostream>
#include <stdio.h>

int funA(int n) {  //nested recursion funk çağrısında kendisini parametre olarak gonderen fonklardır
    if (n > 100)
        return n - 10;
    return funA(funA(n + 11));
}
int main()
{
    int r;
    r = funA(95);    //100 ün altında hangi değeri girersen gir sonuç 91 çıkar ancak 100 ün üstündeki değerler için n-10 değeri doner
    printf("%d", r);  //91
    r = funA(15);
    printf("\n%d", r); //91
    r = funA(200);
    printf("\n%d", r); //190
}
