#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll sum{};
    ll m{};
    ll a;
    while (n--) {
        cin >> a;
        m = max(m, a);
        sum += a;
    }
    m = max(m * 2, sum);
    cout << m;
}
int main() {
    solve();
    return 0;
}
