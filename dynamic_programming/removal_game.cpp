#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int main() {
  int n;
  cin >> n;
  vll arr(n);
  for (auto &a : arr)
    cin >> a;

  vector<vll> dp(n, vll(n, -1));

  for (int len = 1; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;

      if (i == j)
        dp[i][j] = arr[i];

      else if (len == 2) {
        dp[i][j] = max(arr[i], arr[j]);
      }

      else {
        ll left{}, right{};

        // arr[x] + minste mulige etter motstanderens neste trekk. dermed
        // i/j+...
        left = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
        right = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

        dp[i][j] = max(left, right);
      }
    }
  }
  cout << dp[0][n - 1] << '\n';
  return 0;
}
