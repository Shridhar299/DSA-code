#include <iostream>
using namespace std;

class A {
public:
    int marks;

    void getData() {
        cout << "Enter Marks: ";
        cin >> marks;
    }
};

class B : public A {
public:
    void showData() {
        cout << "Entered Marks: " << marks << endl;
    }
};

class C : public B {
};

int main() {
    C obj;
    obj.getData();
    obj.showData();
    return 0;
}

