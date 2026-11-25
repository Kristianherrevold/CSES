#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;cin>>n;
    long long arr[n];
    long long maxElement = INT_MIN;
    for(long long &x : arr) {
        cin>>x;
        maxElement = max(maxElement,x);
    }
    long long curSum = 0, maxSum = 0;
    for(int i = 0; i < n; i++) {
        curSum+=arr[i];
        if(curSum < 0) curSum = 0;
        maxSum = max(curSum, maxSum);
    }
    if(curSum == 0) cout << maxElement;
    else cout << maxSum;
}

int main() {
    solve();
    return 0;
}