#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int solve(int x, vector<long long>& dp) {
    if (x < 0) return 0;

    if (dp[x] != -1) {
        return dp[x];
    }

    long long sum = 0;

    for (int i = 1; i <= 6; i++) {
        sum = (sum + solve(x - i, dp)) % MOD;
    }

    dp[x] = sum;

    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> dp(n + 1, -1);

    dp[0] = 1;
    cout << solve(n, dp);
    return 0;
}
