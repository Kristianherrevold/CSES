#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,l; cin >> n;
    vector<int> lengths;
    for(int i = 0; i < n; i++) {
        cin>>l;
        lengths.emplace_back(l);
    }
    sort(lengths.begin(),lengths.end());
    l = lengths[n/2];
    ll dif = 0;
    for(int i : lengths) {
        dif+=abs(l-i);
    }
    cout << dif;
}

int main() {
    solve();
    return 0;
}