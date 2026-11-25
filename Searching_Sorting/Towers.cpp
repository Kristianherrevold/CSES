#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,h,id; cin>>n;
    multiset<int> towers;
    int count = 1;
    
    while(n--) {
        cin>>h;
        auto it =towers.lower_bound(h+1);
        if(it != towers.end()) {
            towers.erase(it);
            towers.insert(h);
            }
        else {
            towers.insert(h);
        }
    }
    cout << towers.size();
}

int main(){
    solve();
    return 0;
}
