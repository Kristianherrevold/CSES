    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        vector<int> rows = {0,1,2,3,4,5,6,7};
        set<vector<int>> solutions;

        vector<pair<int,int>> reserved;
        string line;
        for(int r = 0; r < 8; r++) {
            cin >> line;
            int c = 0;
            for(char p : line) {
                if(p == '*'){
                    reserved.push_back({r,c});
                }
                c++;
            }
        }

        do{
            bool legal = true;
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    if(i == j){continue;}
                    else if (abs(rows[i]-rows[j]) == abs(i-j)) {
                        legal = false;
                        continue;
                    }
                    for(auto p : reserved) {
                        int r = p.first;
                        int c = p.second;
                        if (rows[c] == r) {
                            legal = false;
                            continue;
                        }
                    }
                }
            }
            if(legal) {
                solutions.insert(rows);
            }
        } while (next_permutation(rows.begin(), rows.end()));

        int s = solutions.size();
        cout << s << endl;
        return 0;
    }