/* Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. 
Find the number(between 1 to N), that is not present in the given array.

Example 1:
Input Format:
 N = 5, array[] = {1,2,4,5}
Result:
 3
Explanation: 
In the given array, number 3 is missing. So, 3 is the answer.
*/




#include <bits/stdc++.h>
using namespace std;

void missingNumber(int a[], int N) {

    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    cout << missingNum << endl;
}

int main()
{
    int N = 5;
    int a[N-1]= {1, 2, 4, 5};
    missingNumber(a, N);
    
    return 0;
}


