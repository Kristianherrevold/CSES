#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    int n, t;
    cin >> n >> t;
    vector<ll> dp(t + 1, -1);
    vector<int> arr(n);

    for (int& a : arr) {
        cin >> a;
    }

    dp[0] = 1;

    for (int i = 1; i <= t; i++) {
        ll ans{};
        for (int j = 0; j < n; j++) {
            if (i - arr[j] == 0)
                ans += 1;
            else if (i - arr[j] < 0)
                continue;
            else
                ans += dp[i - arr[j]];
        }
        dp[i] = ans % MOD;
    }

    cout << dp[t] << '\n';

    return 0;
}
