#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a, b, d;
    cin >> t;
    vector<int> A, B;

    for(int _ = 0; _ < t; _++) {
        cin >> n >> a >> b;
        A.clear();
        B.clear();
        d = n - a - b;
        if(a+b > n) {
            cout << "NO" << endl; 
        }
        else if (n == 1 && abs(a+b) != 0 || (n % 2 == 0 && abs(a-b) == 1)) {
            cout << "NO" << endl;
        }
        else {
            int highA = n, highB = n;
            int lowA = 1, lowB = 1;
            for(int i = 1; i <= a; i++) {
                A.push_back(highA--);
                B.push_back(lowB++);
            }
            for(int i = 1; i <= b; i++) {
                A.push_back(lowA++);
                B.push_back(highB--);
            }
            for(int i = lowA; i < d+lowA; i++) {
                A.push_back(i);
                B.push_back(i);
            }
            cout << "YES" << endl;
            for(int i = 0; i < A.size(); i++) {
                cout << A[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < B.size(); i++) {
                cout << B[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}