#include <iostream>
#include <string>
#include <algorithm>
//a
int main() {
    int len_arr = 0;
    int c = 0;
    std::cin >> len_arr;
    std::cin >> c;
    std::string string;
    std::cin >> string;

    int r = 0;
    int meet_a = 0;
    int meet_b = 0;
    int max_len = 0;
    int badness = 0;
    for (int l = 0; l < len_arr; ++l) {
        while (r < len_arr && badness <= c) {
            if (string[r] == 'a') ++meet_a;
            if (string[r] == 'b') {
                ++meet_b;
                badness += meet_a;
            }
            if (badness > c) max_len = std::max(max_len, (r - 1) - (l - 1));
            else max_len = std::max(max_len, r - l + 1);
            ++r;
        }
        if (string[l] == 'a') {
            --meet_a;
            badness -= meet_b;
        }
        if (string[l] == 'b') --meet_b;
    }
    std::cout << max_len << std::endl;
    return 0;
}