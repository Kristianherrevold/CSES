#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a;
    cin >> n;
    map<ll, ll> prefix;
    prefix[0] = 1;
    ll sum{};
    ll count{};
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        a = ((sum % n) + n) % n;
        if (prefix.count(a)) {
            count += prefix[a];
        }
        prefix[a]++;
    }
    cout << count;
}

int main() {
    solve();
    return 0;
}
