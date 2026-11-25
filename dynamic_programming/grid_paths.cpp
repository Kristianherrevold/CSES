#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1005;
ll dp[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, ' '));

    char a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            grid[i][j] = a;
        }
    }
    if (grid[0][0] != '*') {
        dp[1][1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] != 0 || grid[i - 1][j - 1] == '*') continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}
