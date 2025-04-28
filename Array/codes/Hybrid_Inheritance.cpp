#include <iostream>
using namespace std;

class A {
public:
    int x;
};

class B : public A {
public:
    B() {
        x = 500;
    }
};

class C {
public:
    int y;

    C() {
        y = 100;
    }
};

class D : public B, public C {
public:
    void sum() {
        cout << "Sum = " << x + y << endl;
    }
};

int main() {
    D obj;
    obj.sum();
    return 0;
}

