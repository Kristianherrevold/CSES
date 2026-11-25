#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,a,l; cin>>n;
    vector<int> arriving(n,0);
    vector<int> leaving(n,0);
    for(int i = 0; i<n; i++) {
        cin>>a>>l;
        arriving[i] =a;
        leaving[i] =l;
    }
    sort(arriving.begin(), arriving.end());
    sort(leaving.begin(),leaving.end());
    
    int currentArriving = 0;
    int currentLeaving = 0;
    int maxVisitors = 0, current = 0;
    while(currentLeaving != n && currentArriving != n) {
        l = leaving[currentLeaving];
        a = arriving[currentArriving];
        
        if(a == l) {
            currentArriving++;
            currentLeaving++;
        }
        else if(a<l) {
            current++;
            maxVisitors = max(maxVisitors,current);
            currentArriving++;
        }
        else {
            current--;
            currentLeaving++;
        }
    }
    cout << maxVisitors;
}

int main() {
    solve();
    return 0;
}