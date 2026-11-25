#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, b;
    cin >> n >> b;
    vector<ll> price(n);
    vector<ll> page(n);
    for (ll& p : price) cin >> p;
    for (ll& p : page) cin >> p;

    vector<ll> dp(b + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = b; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
        }
    }

    cout << dp[b] << '\n';
    return 0;
}
