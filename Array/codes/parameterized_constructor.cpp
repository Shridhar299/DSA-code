#include <iostream>
using namespace std;

class Constructor {
private:
    int x, y;

public:
    Constructor(int a, int b) { // Parameterized constructor
        x = a;
        y = b;
        cout << "Sum of x and y is: " << x + y << endl;
    }
};

int main() {
    Constructor c(15, 52); // Passing arguments to the parameterized constructor
    return 0;
}

