#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,p; cin>>n>>m;
    multiset<int> tickets;
    for(int i = 0; i<n; i++) {
        cin>>p;
        tickets.insert(p);
    }
    while(m--) {
        cin>>p;
        auto it = tickets.upper_bound(p);
        if(it != tickets.begin()) {
            it--;
            cout << *it << "\n";
            tickets.erase(it);
        }
        else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}