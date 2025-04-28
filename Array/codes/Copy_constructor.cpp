
/*   A copy constructor is a special constructor in a class that creates
 a new object as a copy of an existing object.
*/


#include <iostream>
using namespace std;

class Example {
private:
    int x, y;

public:
    // Parameterized constructor
    Example(int a, int b) {
        x = a;
        y = b;
    }

    // Copy constructor
    Example(const Example &obj) {
        x = obj.x;
        y = obj.y;
    }

    void display() {
        cout << "x: " << x << ", y: " << y << endl;
    }
};

int main() {
    Example obj1(10, 20); // Create object with parameterized constructor
    Example obj2 = obj1;  // Copy constructor is called

    cout << "Object 1 values: ";
    obj1.display();

    cout << "Object 2 values: ";
    obj2.display();

    return 0;
}

