#include <iostream>
using namespace std;

class A {
public:
    int x;

    void getData() {
        cout << "Enter the value of x: ";
        cin >> x;
    }
};

class B {
public:
    int y;

    void getData1() {
        cout << "Enter the value of y: ";
        cin >> y;
    }
};

class C : public A, public B {
public:
    void sum() {
        cout << "Sum = " << x + y << endl;
    }
};

int main() {
    C obj;
    obj.getData();
    obj.getData1();
    obj.sum();
    return 0;
}

