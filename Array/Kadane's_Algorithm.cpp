#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = 0; // maximum sum
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Add current element to sum

        if (sum > maxi) {
            maxi = sum; // Update maximum sum if current sum is greater
        }

        if (sum < 0) {
            sum = 0; // Reset sum if it becomes negative
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:
    // if (maxi < 0) maxi = 0;

    return maxi;
}

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

