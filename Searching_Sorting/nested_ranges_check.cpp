#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> ranges(n, {0, 0, 0});
  vector<bool> is_nested(n);
  vector<bool> has_nested(n);
  int idx{};
  for (auto &[l, u, i] : ranges) {
    cin >> l >> u;
    i = idx++;
  }

  sort(ranges.begin(), ranges.end(),
       [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
         if (get<0>(a) != get<0>(b)) {
           return get<0>(a) < get<0>(b);
         } else {
           return get<1>(a) > get<1>(b);
         }
       });

  int m;
  m = -INT_MAX;
  for (auto &r : ranges) {
    auto [l, u, i] = r;
    u <= m ? is_nested[i] = 1 : is_nested[i] = 0;
    m = max(m, u);
  }

  sort(ranges.begin(), ranges.end(),
       [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
         if (get<1>(a) != get<1>(b)) {
           return get<1>(a) < get<1>(b);
         } else {
           return get<0>(a) > get<0>(b);
         }
       });

  m = -INT_MAX;
  for (auto &r : ranges) {
    auto [l, u, i] = r;
    l <= m ? has_nested[i] = 1 : has_nested[i] = 0;
    m = max(l, m);
  }

  for (auto a : has_nested)
    cout << a << ' ';
  cout << '\n';
  for (auto a : is_nested)
    cout << a << ' ';
}

int main() {
  solve();
  return 0;
}
