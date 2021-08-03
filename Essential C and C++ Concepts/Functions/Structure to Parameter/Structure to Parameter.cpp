#include <iostream>
using namespace std;

struct callbyvalue {
    int length;
    int breadth;
};
int CallByValueArea(struct callbyvalue exp1) {
    exp1.breadth = 12;  // burada yaptığımız değişikler actual parameterlara yansımayacak
    return exp1.breadth * exp1.length;
}
struct callbyreference {
    int length;
    int breadth;
};
int CallByReferenceArea(struct callbyreference &exp1) {
    exp1.breadth = 12;  // burada yaptığımız değişikler actual parameterlara yansıyacak
    return exp1.breadth * exp1.length;
}
struct callbyadress {
    int length;
    int breadth;
};
int CallByAdressArea(struct callbyadress* exp1) { // burada yaptığımız değişikler actual parameterlara yansıyacak
    exp1->breadth = 12;
    return exp1->breadth * exp1->length;
}
struct test { //Sturct bir array barınddırısa
    int A[5];
    int x;
};
void fonk(struct test *x) { //3 şekilde de çağırabiliriz reference ve adress ile çağırmada actual parametreler değişirken valude actual parameterlar değişmez
    x->A[0] = 12;
}
int main()
{
    struct callbyvalue exp = { 4,6 };
    cout << exp.length<<"-"<<exp.breadth<<"-"<<CallByValueArea(exp)<<endl;
    struct callbyreference exp1 = { 4,6 };
    cout << exp1.length << "-" << exp1.breadth << "-" << CallByReferenceArea(exp1)<<endl;
    struct callbyadress exp2 = { 4,6 };
    cout << exp2.length << "-" << exp2.breadth << "-" << CallByAdressArea(&exp2);
    struct test exp3 = { {1,2,3,4,5},3 };
    fonk(&exp3);
    cout << exp3.A[0];
}
