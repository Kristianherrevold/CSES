#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int a, b;
  cin >> a >> b;
  vector<string> grid(a, "");
  for (auto &line : grid)
    cin >> line;

  vector<vi> visited(a, vi(b, 0));
  vector<pii> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int rooms{};
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {

      if (visited[i][j] || grid[i][j] == '#')
        continue;

      else {
        queue<pii> q;
        visited[i][j] = 1;
        q.push({i, j});
        rooms++;

        while (!q.empty()) {
          pii cur = q.front();
          q.pop();

          for (auto &[c, d] : dir) {
            int nr = cur.first + c;
            int nc = cur.second + d;

            if (nr >= 0 && nr < a && nc >= 0 && nc < b) {
              if (grid[nr][nc] == '.' && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                q.push({nr, nc});
              }
            }
          }
        }
      }
    }
  }
  cout << rooms;
  return 0;
}
