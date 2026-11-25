#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,k,d,s; cin>>n>>m>>k; //folk, hus, diff
    vector<int> desired;
    vector<int> size;
    int a,b;
    int n_ = n;
    int n__ = n;
    int m_ = m;
    while(n_--) {
        cin>>a;
        desired.push_back(a);
    }
    while(m--) {
        cin>>b;
        size.push_back(b);
    }
    sort(desired.begin(),desired.end());
    sort(size.begin(),size.end());
    
    int i = 0;
    int j = 0;
    int c = 0;
    
    
    while(1) {
        d=desired[i];
        s=size[j];
        if(abs(d-s) <= k) {
            i++;
            j++;
            c++;
        }
        else if(d > s) {
            j++;
        }
        else {
            i++;
        }
        if(i >= n__ || j >= m_) break;
    }
    cout << c;

    
}

int main() {
    solve();
    return 0;
}