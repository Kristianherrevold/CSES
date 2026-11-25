#include <bits/stdc++.h>
using namespace std;
void solve(int n, int fra, int til, int hjelp) {
        if(n == 1) {cout << fra << " " << til << endl;}
        else {
            solve((n-1), fra, hjelp, til);
            cout << fra << " " << til << endl;
            solve((n-1), hjelp, til, fra);
        }
    }
    
int main()
{
    int n;cin>>n;
    cout << (pow(2,n) -1) << endl;
    solve(n,1,3,2);
    return 0;
}