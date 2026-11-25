#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);

  int m{};

  for (int &a : arr) {
    cin >> a;
    m = max(m, a);
  }

  vector<ll> H(m + 1, 0);
  vector<ll> D(m + 1, 0);

  H[1] = 1;
  D[1] = 1;

  for (int i = 2; i <= m; i++) {
    H[i] = ((H[i - 1] * 2) % MOD + D[i - 1]) % MOD;
    D[i] = ((D[i - 1] * 4) % MOD + H[i - 1]) % MOD;
  }

  for (int &a : arr) {
    cout << (H[a] + D[a]) % MOD << '\n';
  }

  return 0;
}
