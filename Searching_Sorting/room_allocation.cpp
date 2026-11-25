#include <bits/stdc++.h>

#include <queue>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> guests(n);
    int i{};
    for (auto& [a, b, c] : guests) {
        cin >> a >> b;
        c = i++;
    }
    sort(guests.begin(), guests.end(), [](const auto& A, const auto& B) {
        auto [a, b, c] = A;
        auto [d, e, f] = B;
        if (a != d) {
            return a < d;
        }
        return b < e;
    });
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> assigned_guests;
    priority_queue<int, vector<int>, greater<int>> rooms;
    int b, current_arriving;
    int max_room{};
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        current_arriving = get<0>(guests[i]);
        b = get<1>(guests[i]);
        while (!assigned_guests.empty() && current_arriving > (assigned_guests.top().first)) {
            rooms.emplace(assigned_guests.top().second);
            assigned_guests.pop();
        }
        if (rooms.empty()) {
            max_room++;
            rooms.emplace(max_room);
        }
        int room = rooms.top();
        rooms.pop();
        assigned_guests.emplace(b, room);
        ans[get<2>(guests[i])] = room;
    }
    cout << max_room << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
}
int main() {
    solve();
    return 0;
}
