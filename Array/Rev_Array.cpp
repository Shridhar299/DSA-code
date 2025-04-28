/*  Problem statement
Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

Example:

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}.

Sample Input 1:
2
6 3
1 2 3 4 5 6
5 2
10 9 8 7 6
Sample Output 1:
1 2 3 4 6 5
10 9 8 6 7  */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> Arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> Arr[i];
        }
        
        reverse(Arr.begin() + M + 1, Arr.end());

        for (int i = 0; i < N; ++i) {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

