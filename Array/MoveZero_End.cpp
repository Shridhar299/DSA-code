#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &V, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (V[i] != 0) {
            temp.push_back(V[i]);
        }
    }
    
    // Add the zeros at the end
    while (temp.size() < n) {
        temp.push_back(0);
    }
    
    for (auto ele : temp) {
        cout << ele << " ";
    }
    cout << endl; // Ensure each test case's result is printed on a new line
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> V(n);
        for (int i = 0; i < n; i++) {
            cin >> V[i];
        }
        solve(V, n);
    }
    return 0;
}

