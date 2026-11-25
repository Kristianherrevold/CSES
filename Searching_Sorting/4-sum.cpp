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
    int i1, i2, i3, i4;
    int sum{};
    i1 = 0;
    i4 = n - 1;
    for (i1 = 0; i1 < n - 3; i1++) {
        for (i4 = n - 1; i4 > i1 + 2; i4--) {
            i2 = i1 + 1;
            i3 = i4 - 1;
            while (i3 > i2) {
                sum = arr[i1].first + arr[i2].first + arr[i3].first + arr[i4].first;
                if (sum < t) {
                    i2++;
                } else if (sum > t) {
                    i3--;
                } else {
                    cout << arr[i1].second << ' ' << arr[i2].second << ' ' << arr[i3].second << ' '
                         << arr[i4].second << '\n';
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    solve();
    return 0;
}
