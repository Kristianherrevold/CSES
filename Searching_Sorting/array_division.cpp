#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (ll& x : arr) cin >> x;

    ll lo = *max_element(arr.begin(), arr.end());
    ll hi = accumulate(arr.begin(), arr.end(), 0LL);
    ll ans = hi;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;

        int parts = 1;
        ll sum = 0;
        for (ll x : arr) {
            if (sum + x <= mid) {
                sum += x;
            } else {
                sum = x;
                parts++;
            }
        }

        if (parts <= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
}
