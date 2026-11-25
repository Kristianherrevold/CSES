#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    map<int, int> freq;
    int distinct = 0;
    int left = 0;
    ll ans = 0;

    for (int right = 0; right < n; right++) {
        if (freq[arr[right]]++ == 0) distinct++;

        while (distinct > k) {
            if (--freq[arr[left]] == 0) distinct--;
            left++;
        }

        ans += right - left + 1;
    }

    cout << ans << '\n';
}
