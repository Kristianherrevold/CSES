#include <bits/stdc++.h>

auto permutations(std::vector<char> bokstaver, std::vector<char> prev, std::vector<std::vector<char>>& losninger) -> void {
        int len = bokstaver.size();
        
        for (int i = 0; i < bokstaver.size(); i++) {
            if (i > 0 && bokstaver[i] == bokstaver[i-1]) {
                continue;
            }
            std::vector<char> lsn = prev;
            lsn.push_back(bokstaver[i]);
            std::vector<char> bokstaver_c = bokstaver;
            bokstaver_c.erase(bokstaver_c.begin() + i);

            if(bokstaver_c.size() == 0) {
                losninger.push_back(lsn);
                break;
            }
            permutations(bokstaver_c, lsn, losninger);
        }
    }


int main() {
    std::string input;
    std::cin >> input;
    std::vector<char> bokstaver(input.begin(), input.end());
    std::sort(bokstaver.begin(), bokstaver.end());

    
    std::vector<char> prev;
    std::vector<std::vector<char>> losninger;
    permutations(bokstaver, prev, losninger);

    std::cout << losninger.size() << std::endl;
    for(std::vector<char> lsn : losninger) {
        for(char b : lsn) {
            std::cout << b;
        }
        std::cout << std::endl;
    }
    return 0;
}