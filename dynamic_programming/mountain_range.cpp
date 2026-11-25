#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<pii> arr(n, {0, 0});
  int i{};

  for (auto &[a, idx] : arr) {
    cin >> a;
    idx = i++;
  }

  vector<pii> lr(n, {0, 0});
  stack<int> id;
  int a;

  for (int i = 0; i < n; i++) {
    a = arr[i].first;
    while (!id.empty() && arr[id.top()].first < a) {
      id.pop();
    }
    if (id.empty()) {
      lr[i].first = -1;
    } else {
      lr[i].first = id.top();
    }
    id.push(i);
  }

  id = stack<int>();

  for (int i = n - 1; i >= 0; i--) {
    a = arr[i].first;
    while (!id.empty() && arr[id.top()].first < a) {
      id.pop();
    }
    if (id.empty()) {
      lr[i].second = n;
    } else {
      lr[i].second = id.top();
    }
    id.push(i);
  }

  vector<pii> sorted = arr;
  sort(sorted.begin(), sorted.end());

  vi dp(n, 1);

  for (int i = 0; i < n; i++) {
    int idx = sorted[i].second;
    auto [left, right] = lr[idx];
    int best{};

    for (int l = left + 1; l < idx; l++) {
      best = max(best, dp[l]);
    }
    for (int r = idx + 1; r < right; r++) {
      best = max(best, dp[r]);
    }
    dp[idx] += best;
  }

  int best{};
  for (auto &d : dp) {
    best = max(d, best);
  }

  cout << best << "\n";
  return 0;
}
