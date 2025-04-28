#include <iostream>

using namespace std;

int main()
{
    int a, b;
    
    try
    {
        cout << "Enter the value of a and b\n";
        cin >> a >> b;
        
        if (b == 0) {
            throw (b); // Throw an exception if b is 0
        }
        
        cout << "The result (a/b) = " << a / b << endl;
    }
    catch (int x)
    {
        cout << "Exception caught: division by zero! b = " << x << endl;
    }

    return 0;
}

