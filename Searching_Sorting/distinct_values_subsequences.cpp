#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long MOD = 1e9 + 7;
    unordered_map<long long,int> freq;
    int n,a; cin >> n;
    long long sum = 0;
    if(n) sum = 1;
    while(n--) {
        cin >> a;
        freq[a]++;
    }
    for(const auto& [a,b] : freq) {
       sum=(sum * (b+1)) % MOD; 
    }
    cout << sum-1;
}
int main() {
    solve();
    return 0;
}