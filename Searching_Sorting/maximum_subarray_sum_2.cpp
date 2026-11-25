#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, a, b, p;
    cin >> n >> a >> b;
    ll sum{};
    vector<ll> prefix_sums(n + 1);

    prefix_sums[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> p;
        sum += p;
        prefix_sums[i + 1] = sum;
    }

    multiset<ll> vindu;
    ll ans{LLONG_MIN};

    for (int i = a; i <= n; i++) {
        vindu.insert(prefix_sums[i - a]);

        if (i - b - 1 >= 0) {
            auto it_old = vindu.find(prefix_sums[i - b - 1]);
            vindu.erase(it_old);
        }

        ans = max(ans, (prefix_sums[i] - *vindu.begin()));
    }

    cout << ans;

    return 0;
}
