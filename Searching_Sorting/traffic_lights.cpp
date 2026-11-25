#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l, p; cin >> n >> l;
    set<int> placements;
    multiset<int> lengths;
    lengths.emplace(n);
    placements.emplace(0);
    placements.emplace(n);
    
    int lo, hi;
    while(l--) {
        cin>>p;
        auto it = placements.upper_bound(p);
        hi = *it;
        it--;
        lo = *it;
        lengths.erase(lengths.find(hi-lo));
        lengths.emplace(p-lo);
        lengths.emplace(hi-p);
        placements.emplace(p);
        cout << *lengths.rbegin() << "\n";
    }
}

int main(){
    solve();
    return 0;
}