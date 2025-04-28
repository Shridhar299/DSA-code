/* Problem Statement: Given an array and a sum k, 
we need to print the length of the longest subarray that sums to k.

Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

*/

#include <bits/stdc++.h>
using namespace std;

void getLongestSubarray(vector<int> a, int k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        int s = 0;
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    cout<<len;
}

int main()
{
    vector<int> a = {5,2,3};
    int k = 5;
    getLongestSubarray(a, k);
    return 0;
}
