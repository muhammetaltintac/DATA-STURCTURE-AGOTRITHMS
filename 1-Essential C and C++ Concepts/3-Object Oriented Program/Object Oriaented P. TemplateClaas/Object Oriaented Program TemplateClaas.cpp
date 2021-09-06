#include <iostream>
using namespace std;

template <class T> 
class Arithmetic {
private :
    T a;
    T b;
public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};
template <class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
}
template <class T>
T Arithmetic<T> ::add() {
    T c;
    c = a + b;
    return c;
}
template <class T>
T Arithmetic<T>::sub() {
    T c;
    c = a - b;
    return c;
}

int main()
{
    Arithmetic<int> ar(21, 12);
    cout << ar.add() << "-" << ar.sub()<<endl;
    Arithmetic<double> ar1(2.5, 5.9);
    cout << ar1.add() << "-" << ar1.sub();
}
