#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int n;
  cin >> n;

  vector<string> grid(n, "");
  for (auto &row : grid) {
    cin >> row;
  }

  vector<pii> current = {{0, 0}};
  string ans(1, grid[0][0]);

  for (int steps = 1; steps < 2 * n - 1; steps++) {
    char best = 'Z';

    for (auto &[x, y] : current) {
      if (x + 1 < n) {
        best = min(best, grid[x + 1][y]);
      }

      if (y + 1 < n) {
        best = min(best, grid[x][y + 1]);
      }
    }

    ans += best;

    vi visited(n, 0);
    vector<pii> next;

    for (auto &[x, y] : current) {
      if (x + 1 < n && grid[x + 1][y] == best && !visited[x + 1]) {
        next.push_back({x + 1, y});
        visited[x + 1] = 1;
      }

      if (y + 1 < n && grid[x][y + 1] == best && !visited[x]) {
        next.push_back({x, y + 1});
        visited[x] = 1;
      }
    }

    current = std::move(next);
  }

  cout << ans << '\n';
  return 0;
}
