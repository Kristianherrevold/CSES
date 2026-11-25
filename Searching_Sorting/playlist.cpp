#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    std::vector<int> songs(n);
    for(int &s:songs) cin>>s;
    int start = 0;
    int maxLength = 1;
    map<int, int> playlist;
    for(int i = 0; i < n; i++) {
        if(playlist[songs[i]]) {
            start = max(start,playlist[songs[i]]);
        }
        playlist[songs[i]] = i+1;
        maxLength=max(maxLength, i-start+1);
    }
    cout << maxLength;
}


int main() {
	solve();
	return 0;
}