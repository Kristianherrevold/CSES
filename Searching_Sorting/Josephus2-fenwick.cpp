#include <bits/stdc++.h>
using namespace std;

void updateBIT(int BITree[], int n, int index, int val) {
  index = index + 1; // 0 til 1 indeksering
  while (index <= n) {
    BITree[index] += val;
    index +=
        index & (-index); // til forelder, aka 01011 - 01100 - 01000 - 10000 etc, altså lgger til LSB hver gang, dermed logN, siden det kun er dise som har ansvaret å holdeverdien
  }
}

int getSum(int BITree[], int index) {
  int sum = 0;
  index = index + 1; // til 1-indeksering
  while (index > 0) {
    sum += BITree[index];
    index -= index & (-index); //si 13, da: 1101 + 1100 + 1000, altså 13 + (9 til 12) + (1 til 8)
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

// josephus 2
int findTarget(int target, int BITree[], int  n) {
    int pos = 0;
  int logN = log2(n);
  for (int r = logN; r >= 0; r--) {
int next = pos + (1 << r);
    if (next <= n && BITree[next] < target) {
      pos = next;
      target -= BITree[next];
    }
  }
  return pos + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i] = 1;
  int *BITree = constructBITree(arr, n);

  int target = k % n + 1;
  int a;
  int remaining = n;
  while (remaining > 0) {
    a = findTarget(target, BITree, n);
    cout << a << ' ';
    updateBIT(BITree, n, a - 1, -1);
    remaining--;
    if (remaining > 0) {
      target = (target - 1 + k) % remaining + 1;
    }
  }
}
