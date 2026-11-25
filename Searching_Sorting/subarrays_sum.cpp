#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll t, sum;
    sum = 0;
    cin >> t;
    vector<int> arr(n);
    for (auto& a : arr) cin >> a;
    int s{};
    int a{};
    for (int b = 0; b < n; b++) {
        sum += arr[b];
        while (sum > t && b >= a) {
            sum -= arr[a];
            a++;
        }
        if (sum == t) {
            s++;
        }
    }
    cout << s;
}

int main() {
    solve();
    return 0;
}
