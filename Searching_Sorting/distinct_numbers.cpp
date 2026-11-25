#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t; cin >>n;
    set<int> a;
    while(n--) {
        cin>>t;
        a.insert(t);
    }
    cout << a.size();
    return;
}
int main() {
    solve();
    return 0;
}