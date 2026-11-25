#include <bits/stdc++.h>
static void print_binary(int x, int length) {
    for(int i = length-1; i >= 0; i--) {
        std::cout << ((x >> i) & 1);
    }
    std::cout << std::endl;
}
int main() {
    int n;
    std::cin >> n;
    int size = 1 << n;
    std::vector<int> graycode;
    for(int i = 0; i < size; i++) {
        graycode.emplace_back(i ^ (i >> 1));
    }
    for(int i = 0; i < size; i++) {
        print_binary(graycode[i],n);
    }
}
