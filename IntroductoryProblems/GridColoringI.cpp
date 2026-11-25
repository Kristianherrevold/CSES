#include <bits/stdc++.h>
using namespace std;

void solve() {
    int c,r;cin>>r>>c;
    string line;
    vector<string> matrix;
    for(int i = 0; i < r; i++) {
        cin>>line;
        matrix.push_back(line);
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            for(int n = 0; n <4; n++) {
                char candidate = 'A'+n;
                if(candidate == matrix[i][j]) continue;
                if(i>0 && candidate == matrix[i-1][j]) continue;
                if(j>0 && candidate == matrix[i][j-1]) continue;
                matrix[i][j] = candidate;
                cout << candidate;
                break;
            }
        }
        cout << '\n';
    }
}

int main(){
    solve();
    return 0;
}