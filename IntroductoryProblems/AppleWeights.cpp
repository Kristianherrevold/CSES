#include <bits/stdc++.h>
using namespace std;

int min_diff(vector<int> weights) {
    int n = weights.size();
    long long diff = INT_MAX;
    long long i_diff;
    for (int i = 0; i < (1 << n); i++) {
        i_diff = 0;
        bitset<20> ib(i);
        for (int j = 0; j < n; j++) {
            if (ib[j] == 1) {
                i_diff += weights[j];
            }
            else {
                i_diff -= weights[j];
            }
        }
        diff = min(diff, abs(i_diff));

    }
    return diff;
}

int main() {
int n;
cin >> n;

vector<int> weights;
for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    weights.push_back(a);
}
int diff = min_diff(weights);
cout << diff << endl;
}