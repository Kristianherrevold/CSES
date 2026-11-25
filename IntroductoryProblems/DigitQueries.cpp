#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k, q; cin>>q;
    while(q--) {
        cin >> k;
        int i = 1;
        long long p = 1;
        while(k > p * i * 9) {
            k -= p * i * 9;
            i++;
            p *= 10;
        }
        k--;
        long long n = p + k/i;
        int d = k % i;
        string num = to_string(n);
        cout << num[d] << '\n';
}
}

int main(){
    solve();
    return 0;
}