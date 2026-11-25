#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pii> connections(m);
  vector<vi> adj(n);
  for (auto &[a, b] : connections) {
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vi parents(n, -1);
  parents[0] = 0;
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == n - 1) {
      vi path;
      for (int v = cur;; v = parents[v]) {
        path.push_back(v);
        if (v == 0)
          break;
      }
      reverse(path.begin(), path.end());
      cout << path.size() << '\n';
      for (auto &p : path) {
        cout << p + 1 << ' ';
      }
      return 0;
    }
    for (auto &nx : adj[cur]) {
      if (parents[nx] != -1)
        continue;
      parents[nx] = cur;
      q.push(nx);
    }
  }
  cout << "IMPOSSIBLE" << '\n';
  return 0;
}
