#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin>>n;
    std::vector<int> numbers(n,0);
    for(int &x:numbers) cin>>x;
    sort(numbers.begin(),numbers.end());
    ll reach = 0;
    for(int c : numbers) {
        if(c <= reach+1) reach += c;
        else break;
    }
    cout << reach+1;
}

int main() {
    solve();
    return 0;
}