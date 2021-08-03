#include <iostream>
using namespace std;
class Rectangle {  //class yerine struct a yazabilirdik  structın classtan farkı tüm üyeleri publictir
public:
    int length;
    int breadth;
    void initialize(int l, int b) {
        length = l;
        breadth = b;
    }
    int area() {
        return  length * breadth;
    }
    int perimeter() {
        return 2 * (length + breadth);
    }
};
int main()
{
    Rectangle rec;
    int ar = 0, peri = 0;
    int l, b;
    cin >> l >> b;
    rec.initialize(l,b);
    ar=rec.area();
    peri=rec.perimeter();
    cout << "length: " << rec.length << "   -   " << "breadth: " << rec.breadth << endl;
    cout << "area: " << ar << " -   " << "perimeter: " << peri << endl;
}

