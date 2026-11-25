#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,s,e; cin >> n;
    set<pair<int,int>> times;
    for(int i = 0; i< n; i++){
        cin>>s>>e;
        times.emplace(e,s);
    }
    auto it = times.begin();
    int currentEnd = 0;
    int highest = 0;
    while(it != times.end()) {
        if(it->second >= currentEnd) {
            highest++;
            currentEnd = it->first;
        }
        it++;
    }
    cout << highest;
}

int main() {
    solve();
    return 0;
}