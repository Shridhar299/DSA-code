#include <iostream>
using namespace std;

class Constructor {
private:
    int x, y;

public:
    Constructor() {
        x = 10;
        y = 90;
        cout << "Sum of x and y is: " << x + y << endl;
    }
};

int main() {
    Constructor c;
    return 0;
}

