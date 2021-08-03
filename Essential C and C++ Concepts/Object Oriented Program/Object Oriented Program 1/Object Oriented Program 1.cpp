#include <iostream>
using namespace std;
class Rectangle {
private:
    int length;
    int breadth;
public:
    Rectangle() {
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }
    int area() {
        return length * breadth;
    }
    int perimeter() {
        return 2 * (length + breadth);
    }
    int getLength() {
        return length;
    }
    void setLength(int l) {
        length = l;
    }
    int getBreadth() {
        return breadth;
    }
    void setBreadth(int b) {
        breadth = b;
    }
    ~Rectangle() {
        cout << "Destructure worked" << endl;
    }
};
int main()
{
    Rectangle rec;
    rec.setLength(15);
    rec.setBreadth(10);
    int ar = 0, peri = 0;
    ar = rec.area();
    peri = rec.perimeter();
    cout << "length: " << rec.getLength() << "    -   breadth: " << rec.getBreadth() << endl;
    cout << "area: " << ar << "   -   perimeter: " << peri << endl;
}
