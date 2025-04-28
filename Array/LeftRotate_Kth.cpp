#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n) {
    int k;
    cin >> k;
    k = k % n; // Handle cases where k >= n
    for (int j = 0; j < k; j++) {
        int temp = arr[0];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, n);
    }
    return 0;
}

