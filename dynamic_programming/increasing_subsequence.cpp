#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int n;
  cin >> n;

  vi tails;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    int low = 0, high = tails.size();

    while (low < high) {
      int mid = low + (high - low) / 2;
      if (tails[mid] < x)
        low = mid + 1;
      else
        high = mid;
    }

    if (low == (int)tails.size())
      tails.push_back(x);
    else
      tails[low] = x;
  }

  cout << tails.size() << "\n";
}
