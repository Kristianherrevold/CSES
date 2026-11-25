#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int pivot;
	int ground = 1;
	int celing = 1e9;
	int n = 0;
	while(n<31) {
	    pivot = (celing+ground)/2;
    	cout << "? " << pivot << endl;
    	string a; cin >> a;
    	if(a == "NO") {
    	    celing = pivot;
    	}
    	else if(a == "YES") {
    	    ground = pivot+1;
    	}
    	if(ground == celing) {
    	    cout << "! " << ground;
    	    break;
    	}
    	n++;
	}
}

int main() {
	solve();
	return 0;
}
