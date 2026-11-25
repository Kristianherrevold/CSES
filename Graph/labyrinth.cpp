#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int rows, cols;
  cin >> rows >> cols;

  vector<string> grid(rows);
  for (auto &row : grid) {
    cin >> row;
  }

  pii start, end;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      char current = grid[row][col];
      if (current == 'A')
        start = {row, col};
      if (current == 'B')
        end = {row, col};
    }
  }

  vector<vector<pair<pii, char>>> parents(rows, vector<pair<pii, char>>(cols));
  vector<vi> visited(rows, vi(cols, 0));
  vector<pair<pii, char>> dir = {
      {{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}};
  queue<pii> q;
  q.push(start);

  visited[start.first][start.second] = 1;
  bool possible = 0;

  while (!q.empty()) {
    if (possible)
      break;
    pii current = q.front();
    q.pop();
    for (auto &[D, dir] : dir) {
      int ny = current.first + D.first;
      int nx = current.second + D.second;
      if (ny >= 0 && ny < rows && nx >= 0 && nx < cols && !visited[ny][nx] &&
          grid[ny][nx] != '#') {
        visited[ny][nx] = 1;
        parents[ny][nx] = make_pair(current, dir);
        q.push({ny, nx});
        if (make_pair(ny, nx) == end) {
          possible = 1;
          break;
        }
      }
    }
  }

  if (!possible) {
    cout << "NO" << '\n';
    return 0;
  }

  cout << "YES" << '\n';
  pii current = end;
  string result = "";

  while (current != start) {
    result.push_back(parents[current.first][current.second].second);
    current = parents[current.first][current.second].first;
  }
  reverse(result.begin(), result.end());

  cout << result.size() << '\n' << result << '\n';
  return 0;
}
