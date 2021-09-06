#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void initialise(struct Rectangle* r, int l, int b) {
    r->breadth = b;
    r->length = l;
}
int area(struct Rectangle r) {
    int p;
    p = r.length * r.breadth;
    return p;

}
int perimeter(struct Rectangle r) {
    return 2 * (r.breadth + r.length);
}
int main()
{
    Rectangle rec = { 0,0 };
    int l, b;
    cin >> l>> b;
    initialise(&rec, l, b);
    int a=area(rec);
    int peri=perimeter(rec);
    cout << a << "-"<< peri << endl;
}

