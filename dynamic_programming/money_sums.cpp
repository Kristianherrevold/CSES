#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int n;
  cin >> n;

  vi arr(n, 0);
  int sum{};
  for (auto &a : arr) {
    cin >> a;
    sum += a;
  }

  vi dp(1e6, 0);
  vi ans;

  dp[0] = 1;

  for (auto &coin : arr) {
    for (int i = sum; i > coin - 1; i--) {
      if (dp[i - coin]) {
        if (!dp[i]) {
          ans.push_back(i);
        }
        dp[i] = 1;
      }
    }
  }

  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for (auto &a : ans) {
    cout << a << " ";
  }

  cout << '\n';

  return 0;
}
