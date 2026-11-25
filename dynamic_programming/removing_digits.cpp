#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans{};
    int temp, d;
    while (n != 0) {
        temp = n;
        d = 0;
        while (temp != 0) {
            int current = temp % 10;
            d = max(current, d);
            temp /= 10;
        }
        n -= d;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
