#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> arr(n);
    int i = 1;
    for (auto& [a, b] : arr) {
        cin >> a;
        b = i++;
    }
    sort(arr.begin(), arr.end());
    int sum{};
    for (int i{}; i < n - 1; i++) {
        int i2 = i + 1;
        int i3 = n - 1;
        if (i2 == i || i3 == i || i2 == i3) continue;
        sum = arr[i].first + arr[i2].first + arr[i3].first;
        while (i3 > i2) {
            if (sum > t) {
                i3--;
            } else if (sum < t) {
                i2++;
            } else {
                cout << arr[i].second << ' ' << arr[i2].second << ' ' << arr[i3].second << '\n';
                return;
            }
            sum = arr[i].first + arr[i2].first + arr[i3].first;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
int main() {
    solve();
    return 0;
}
