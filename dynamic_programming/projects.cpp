#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef tuple<int, int, int> tiii;

int bin_search(const vector<tiii> &arr, int start) {
  int low = 0;
  int high = (int)arr.size() - 1;
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (get<0>(arr[mid]) < start) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<tiii> arr(n);
  for (auto &[end, start, reward] : arr) {
    cin >> start >> end >> reward;
  }
  sort(arr.begin(), arr.end());
  vector<ll> dp(n, 0);

  for (int i = 0; i < n; i++) {
    int prev_before_start = bin_search(arr, get<1>(arr[i]));
    dp[i] = max(i > 0 ? dp[i - 1] : 0,
                prev_before_start >= 0 ? dp[prev_before_start] + get<2>(arr[i])
                                       : get<2>(arr[i]));
  }

  cout << dp[n - 1];
  return 0;
}
