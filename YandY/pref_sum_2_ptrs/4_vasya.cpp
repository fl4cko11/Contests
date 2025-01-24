#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int len_arr = 0;
    int k = 0;
    int max_len = 0;
    std::cin >> len_arr;
    std::cin >> k;
    std::vector<int> arr;
    int unit = 0;
    for (int j = 0; j < len_arr; ++j) {
        std::cin >> unit;
        arr.push_back(unit);
    }

    std::sort(arr.begin(), arr.end());

    int r = 0;
    for (int l = 0; l < len_arr; ++l) {
        while (r < len_arr && arr[r] - arr[l] <= k) {
            max_len = std::max(max_len, r + 1 - l);
            ++r;
        }
    }
    std::cout << max_len << std::endl;
    return 0;
}