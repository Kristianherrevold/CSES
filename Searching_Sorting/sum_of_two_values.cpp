#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,target,num,sum;cin>>n>>target;
    vector<pair<int,int>> numbers;
    for(int i = 0; i < n; i++) {
        cin >> num;
        numbers.emplace_back(num,i+1);
    }
    sort(numbers.begin(),numbers.end());
    int right = n-1;
    int left = 0;
    while(right!=left) {
        sum = numbers[right].first + numbers[left].first;
        if(sum > target) right--;
        else if(sum < target) left++;
        else {
            cout << numbers[left].second << " " << numbers[right].second << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    solve();
    return 0;
}