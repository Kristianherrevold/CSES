#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int start{0};
    long long sum{0};
    unordered_set<int> seen;
    vector<int> nums(n);
    for(int &x:nums) cin>>x;
    
    for(int i = 0; i < n; i++) {
        while(seen.count(nums[i])) {
            seen.erase(nums[start]);
            start++;
        }
        seen.emplace(nums[i]);
        sum+=i-start+1;
    }
    cout << sum;
}

int main() {
    solve();
    return 0;
}