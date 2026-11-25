#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> dp(t + 1, 1e9);
    vector<int> arr(n);

    for (int& a : arr) {
        cin >> a;
    }

    dp[0] = 0;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (i - arr[j] < 0) continue;
            dp[i] = min(dp[i], dp[i - arr[j]] + 1);
        }
    }
    cout << (dp[t] == 1e9 ? -1 : dp[t]) << '\n';
    return 0;
}
