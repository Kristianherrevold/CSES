#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    vector<vector<int>> v(n,vector<int>(n, -1));
    v[0][0] = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    int x,y;
    int s = v.size() - 1;
    
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        if(y-2 >= 0 && x-1 >= 0) {
            if(v[y-2][x-1] == -1){
                q.push({y-2,x-1});
                v[y-2][x-1] = v[y][x] + 1;
            }
        }
        if(y-2 >= 0 && x+1 <= s) {
            if(v[y-2][x+1] == -1){
                q.push({y-2,x+1});
                v[y-2][x+1] = v[y][x] + 1;
            }
        }
        
        if(y-1 >= 0 && x-2 >= 0) {
            if(v[y-1][x-2] == -1){
                q.push({y-1,x-2});
                v[y-1][x-2] = v[y][x] + 1;
            }
        }
        if(y+1 <= s && x-2 >= 0) {
            if(v[y+1][x-2] == -1) {
                q.push({y+1,x-2});
                v[y+1][x-2] = v[y][x] + 1;
            }
        }
        
        if(y+2 <= s && x-1 >= 0) {
            if(v[y+2][x-1] == -1) {
                q.push({y+2,x-1});
                v[y+2][x-1] = v[y][x] + 1;
            }
        }
        if(y+2 <= s && x+1 <= s) {
            if(v[y+2][x+1] == -1) {
                q.push({y+2,x+1});
                v[y+2][x+1] = v[y][x] + 1;
            }
        }
        
        if(y-1 >= 0 && x+2 <= s) {
            if(v[y-1][x+2] == -1) {
                q.push({y-1,x+2});
                v[y-1][x+2] = v[y][x] + 1;
            }
        }
        if(y+1 <= s && x+2 <= s) {
            if(v[y+1][x+2] == -1) {
                q.push({y+1,x+2});
                v[y+1][x+2] = v[y][x] + 1;
            }
        }
    }
    for(int i = 0; i <= s; i++) {
        for(int j = 0; j <= s; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    solve(n);
    return 0;
}