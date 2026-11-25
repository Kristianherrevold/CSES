#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> t(n);
    for (auto& [a, b] : t) cin >> a >> b;
    sort(t.begin(), t.end());
    ll time{};
    ll sum{};
    for (auto& [a, b] : t) {
        sum += (b - a - time);
        time += a;
    }
    cout << sum;
}

int main() {
    solve();
    return 0;
}
