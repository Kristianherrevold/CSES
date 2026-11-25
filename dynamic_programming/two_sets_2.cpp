#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  int sum = n * (1 + n) / 2;
  if (sum % 2 != 0) {
    cout << 0 << '\n';
    return 0;
  }

  int target = sum / 2;
  vll dp(target + 1, 0);
  dp[0] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = target; j >= i; j--) {
      dp[j] = (dp[j] + dp[j - i]) % MOD;
    }
  }

  cout << dp[target] << '\n';
  return 0;
}
