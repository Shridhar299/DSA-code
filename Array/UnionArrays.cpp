#include <bits/stdc++.h>
#include <set>
using namespace std;

void FindUnion(int arr1[], int arr2[], int n, int m) {
    set<int> s;

    // Insert elements from the first array into the set
    for (int i = 0; i < n; i++) {
        s.insert(arr1[i]);
    }

    // Insert elements from the second array into the set
    for (int i = 0; i < m; i++) {
        s.insert(arr2[i]);
    }

    // Print the union of both arrays
    for (auto val : s) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};

    FindUnion(arr1, arr2, n, m);

    return 0;
}

