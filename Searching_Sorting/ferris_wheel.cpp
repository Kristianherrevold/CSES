#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,w,p; cin >> n >> w;
    vector<int> weight(n);
    
    for(int &p:weight) cin>>p;
    sort(weight.begin(),weight.end());
    
    int gondolas = 0, i = 0, j = n-1;
    while(1) {
        if(j<i) {
            break;
        }
        if(i==j) {
            gondolas++; break;
        }
        if(weight[i] + weight[j] > w) {
            gondolas++;
            j--;
        }
        else {
            gondolas++;
            i++;
            j--;
        }
    }
    cout << gondolas << "\n";
}

int main() {
    solve();
    return 0;
}