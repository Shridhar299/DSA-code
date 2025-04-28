#include <iostream>
using namespace std;

class A {
public:
    int x, y;

    void getData() {
        cout << "Enter value of x: ";
        cin >> x;
        cout << "Enter value of y: ";
        cin >> y;
    }
};

class B : public A {
public:
    void showSum() {
        cout << "Sum of x and y is: " << x + y << endl;
    }
};

class C : public A {
public:
    void showProduct() {
        cout << "Product of x and y is: " << x * y << endl;
    }
};

int main() {
    B obj1;
    C obj2;
    obj1.getData();
    obj1.showSum();
    obj2.getData();
    obj2.showProduct();
    return 0;
}

