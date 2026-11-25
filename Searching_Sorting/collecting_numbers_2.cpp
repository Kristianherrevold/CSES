#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m, v,s; cin >> n >> s;
    vector<int> pos(n+1);
    vector<int> number(n+1);
    for(int i = 1; i <= n; i++){
        cin>>v;
        pos[v] = i;
        number[i] = v;
    }
    
    int rounds = 1;
    for(int i = 2; i <= n; i++) {
       if(pos[i] < pos[i-1]) rounds++;
    }
    
    int a,b;
    int valA,valB;
    while(s--) {
        cin>>a>>b;
        valA = number[a];
        valB = number[b];
        
        set<pair<int, int>> pairs;
        if (valA > 1) pairs.insert({valA-1, valA});
        if (valA < n) pairs.insert({valA, valA+1});
        if (valB > 1) pairs.insert({valB-1, valB});
        if (valB < n) pairs.insert({valB, valB+1});
        
        for(auto p : pairs) {
            if(pos[p.second] < pos[p.first]) rounds--;
        }
        
        swap(number[a],number[b]);
        
        pos[valA] = b;
        pos[valB] = a;
        
        for(auto p : pairs) {
            if(pos[p.second] < pos[p.first]) rounds++;
        }
        
        cout << rounds << "\n";
    }
}

int main() {
	solve();
	return 0;
}