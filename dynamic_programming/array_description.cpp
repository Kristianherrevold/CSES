#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 2, 0));
    vector<ll> arr(n);

    for (ll& a : arr) {
        cin >> a;
    }

    if (arr[0] == 0) {
        for (int v = 1; v <= m; v++) {
            dp[0][v] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int v = 1; v <= m; v++) {
            if (arr[i] == 0 || arr[i] == v) {
                dp[i][v] = (dp[i - 1][v - 1] + dp[i - 1][v] + dp[i - 1][v + 1]) % MOD;
            } else {
                dp[i][v] = 0;
            }
        }
    }

    ll ans{};

    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n - 1][i]) % MOD;
    }

    cout << ans;
}
