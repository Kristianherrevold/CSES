#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void dfs(int u, vector<vi> &adj, vi &visited) {
  visited[u] = 1;

  for (int v : adj[u]) {
    if (!visited[v]) {
      dfs(v, adj, visited);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vi> adj(n);
  vi visited(n, 0);
  vi components;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      components.push_back(i);
      dfs(i, adj, visited);
    }
  }

  cout << components.size() - 1 << '\n';

  for (int i = 1; i < (int)components.size(); i++) {
    cout << components[i - 1] + 1 << " " << components[i] + 1 << '\n';
  }
}
