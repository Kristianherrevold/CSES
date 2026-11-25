#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    set<int> nums;
    for(int i = 1; i <= n; i++) nums.emplace(i);
    auto it = nums.begin();
    it++;
    for(int i = 0; i < n; i++) {
        if(nums.size() == 1) {
            cout << *nums.begin() << "\n";
        }
        else {
            cout << *it << "\n";
            it = nums.erase(it);
            if(it == nums.end()) it=nums.begin();
            it++;
            if(it == nums.end()) it=nums.begin();
        }
    }
}

int main(){
    solve();
    return 0;
}