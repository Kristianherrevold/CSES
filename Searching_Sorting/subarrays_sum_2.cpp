#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a;
    cin >> n;
    ll t;
    cin >> t;
    ll sum{};
    ll count{};
    map<ll, ll> prefix;
    prefix[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        if (prefix.count(sum - t)) {
            count += prefix[sum - t];
        }
        prefix[sum]++;
    }
    cout << count;
}

int main() {
    solve();
    return 0;
}
