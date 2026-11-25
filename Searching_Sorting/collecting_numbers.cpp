#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n,v;
	cin>>n;
	int rounds = 1;
	vector<int> pos(n,0);
	for(int i = 0; i < n; i++) {
		cin>>v;
		pos[v] = i;
	}
	for(int i = 0; i < n; i++) {
		if(pos[i]>pos[i+1]) rounds++;
	}
	cout << rounds;
}

int main() {
	solve();
	return 0;
}