#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void updateBIT(int BITree[], int n, int index, int val) {
  index++;
  while (index <= n) {
    BITree[index] += val;
    index += index & (-index);
  }
}
int getSum(int BITree[], int index) {
  index++;
  int sum{0};
  while (index > 0) {
    sum += BITree[index];
    index -= index & (-index);
  }
  return sum;
}

int *constructBITree(int arr[], int n) {
  int *BITree = new int[n + 1]{0};
  for (int i = 0; i < n; i++) {
    updateBIT(BITree, n, i, arr[i]);
  }
  return BITree;
}

void solve() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> ranges(n, {0, 0, 0});
  vector<int> ans(n, 0);
  int i{0};
  for (auto &[l, u, idx] : ranges) {
    cin >> l >> u;
    idx = i++;
  }

  sort(ranges.begin(), ranges.end(),
       [](const tuple<int, int, int> &A, const tuple<int, int, int> &B) {
         auto [a1, b1, id1] = A;
         auto [a2, b2, id2] = B;
         if (a1 != a2) {
           return a1 > a2;
         }
         return b1 < b2;
       });

  vector<int> arr(n);
  i = 0;
  for (auto &[a, b, c] : ranges) {
    arr[i++] = b;
  }
  sort(arr.begin(), arr.end());
  int *zero_n = new int[n]{0};
  int *BITree = constructBITree(zero_n, n);
  int inserted_count{0};
  for (auto &[a, b, idx] : ranges) {
    auto rang = lower_bound(arr.begin(), arr.end(), b) - arr.begin();
    int count = getSum(BITree, rang);
    updateBIT(BITree, n, rang, 1);
    ans[idx] = count;
  }
  for (int a : ans) {
    cout << a << ' ';
  }
  cout << '\n';

  vector<int> ans2(n);
  sort(ranges.begin(), ranges.end(),
       [](const tuple<int, int, int> &A, const tuple<int, int, int> &B) {
         auto [a1, b1, id1] = A;
         auto [a2, b2, id2] = B;
         if (a1 != a2) {
           return a1 < a2;
         }
         return b1 > b2;
       });

  i = 0;
  for (auto &[a, b, c] : ranges) {
    arr[i++] = b;
  }

  sort(arr.begin(), arr.end());
  // arr.erase(unique(arr.begin(), arr.end()), arr.end());
  int *BITree2 = constructBITree(zero_n, n);
  inserted_count = 0;
  for (auto &[a, b, idx] : ranges) {
    auto rang = lower_bound(arr.begin(), arr.end(), b) - arr.begin();
    int count = inserted_count - getSum(BITree2, rang - 1);
    updateBIT(BITree2, n, rang, 1);
    inserted_count++;
    ans2[idx] = count;
  }
  for (int a : ans2) {
    cout << a << ' ';
  }
  cout << '\n';
}

int main() {
  solve();
  return 0;
}
