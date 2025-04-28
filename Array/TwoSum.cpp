#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        vector<int> V(n);
        for (int i = 0; i < V.size(); i++) {
            cin >> V[i];
        }
        int target = 14;

        vector<int> ans = twoSum(n, V, target);
        cout << "This is the answer for variant 2: [" << ans[0] << ", " << ans[1] << "]" << endl;
    }
    return 0;
}

