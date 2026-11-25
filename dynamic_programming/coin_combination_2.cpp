#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

// loop gjennom alle myntene, lag summen opp til i, dp[i]
int main() {
    int n, t;
    cin >> n >> t;
    vector<ll> dp(t + 1, 0);
    vector<int> arr(n);

    for (auto& a : arr) {
        cin >> a;
    }

    dp[0] = 1;

    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= t; i++) {
            if (i - arr[j] < 0)
                continue;
            else {
                dp[i] = (dp[i] + dp[i - arr[j]]) % MOD;
            }
        }
    }

    cout << dp[t] << '\n';
    return 0;
}
