#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);

    for (auto& [end, start] : movies) {
        cin >> start >> end;
    }

    sort(movies.begin(), movies.end());

    multiset<int> members;
    for (int i = 0; i < k; i++) {
        members.insert(0);
    }

    int ans = 0;

    for (const auto& [end, start] : movies) {
        auto it = members.upper_bound(start);
        if (it == members.begin()) {
            continue;
        }
        --it;
        members.erase(it);
        members.insert(end);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
