#include <bits/stdc++.h>
using namespace std;

string solve(string line){
    map<char,int> letters;
    string res = {};
    for(const auto& c:line) {
        letters[c]++;
    }
    int m = max_element(letters.begin(), letters.end(),
            [] (const auto& a, const auto& b) 
            {return (a.second < b.second);})->second;
            
    if(m > (line.size()+1)/2) {
        cout << -1;
    }
    else {
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<>> pq;
        
        for(auto& [ch, freq] : letters) {
            pq.push({ch,freq});
        }
        string result = {};
        char prev = '\0';
        while(!pq.empty()) {
            auto [ch,cnt] = pq.top(); pq.pop();
            if(ch == prev) {
                if(pq.empty()){cout << -1; return "-1";}
                auto [ch2,cnt2] = pq.top(); pq.pop();
                result += ch2;
                if(cnt2 - 1 > 0) {
                    pq.push({ch2,cnt2-1});
                }
                pq.push({ch,cnt});
            }
            else {
                result+=ch;
                if(cnt-1 > 0) {
                    pq.push({ch,cnt-1});
                }
            }
            prev = result.back();
        }
        res+=result;
    }
    return res;
}

int main(){
    string line; cin >> line;
    sort(line.begin(),line.end());
    line = solve(line);
    cout << line << "\n";
    reverse(line.begin(),line.end());
    line = solve(line);
    cout << line;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    int freq[26] = {};
    for (char c : s) freq[c - 'A']++;

    string res;

    for (int i = 0; i < n; i++) {
        int rem = n - i - 1;
        bool placed = false;

        for (int j = 0; j < 26; j++) {
            if (freq[j] == 0) continue;
            if (!res.empty() && res.back() == 'A' + j) continue;

            freq[j]--;
            int maxFreq = *max_element(freq, freq + 26);
            
            if (maxFreq <= (rem + 1) / 2) {
                res += 'A' + j;
                placed = true;
                break;
            }

            freq[j]++; // ikke gyldig, angre
        }

        if (!placed) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << res << '\n';
}

#include <bits/stdc++.h>
using namespae std;

void solve() {
    
}