#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll g;
    cin >> g;
    vector<ll> ms(n);
    for (auto& m : ms) cin >> m;
    ll b = 1e18;
    ll sum{};
    ll upper = 1e18;
    ll lower = 1;
    while (upper > lower) {
        ll c = lower + (upper - lower) / 2;
        for (auto& m : ms) {
            sum += c / m;
            if (sum >= g) {
                break;
            }
        }
        if (sum >= g) {
            b = min(c, b);
            upper = c;
        } else if (sum < g) {
            lower = c + 1;
        }
        sum = 0;
    }
    cout << b;
}
int main() {
    solve();
    return 0;
}
