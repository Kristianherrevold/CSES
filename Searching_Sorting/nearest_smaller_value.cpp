#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a;
  cin >> n;
  vector<int> t(n);
  for (auto &j : t) {
    cin >> j;
  }
  stack<int> id;
  for (int i = 0; i < n; i++) {
    a = t[i];

    while (!id.empty() && t[id.top()] >= a) {
      id.pop();
    }

    if (id.empty()) {
      cout << 0 << ' ';
    } else {
      cout << id.top() + 1 << ' ';
    }
    id.push(i);
  }
}

int main() {
  solve();
  return 0;
}
