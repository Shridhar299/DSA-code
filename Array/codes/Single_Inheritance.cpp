#include <iostream>
using namespace std;

class Base {
public:
    int x;

    void getData() {
        cout << "Enter the value of x: ";
        cin >> x;
    }
};

class Derived : public Base {
public:
	int y;
    void readData() {
        cout << "Enter the value of y: ";
        cin >> y;
    }

    void product() {
        cout << "Product = " << x * y << endl;
    }
};

int main() {
    Derived obj;
    obj.getData();
    obj.readData();
    obj.product();
    return 0;
}

