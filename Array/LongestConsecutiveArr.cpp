#include <bits/stdc++.h>
using namespace std;

// Function to find the longest consecutive sequence
int longestSeq(vector<int> a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    // Insert all elements into the set
    for (int num : a) {
        st.insert(num);
    }

    // Find the longest consecutive sequence
    for (int num : st) {
        if (st.find(num - 1) == st.end()) {
            int cnt = 1;
            int x = num;
            while (st.find(x + 1) != st.end()) {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int result = longestSeq(a);
    cout << "The longest consecutive sequence is " << result << "\n";
    return 0;
}

