#include <iostream>
#include <vector>

int main() {
    int len_arr = 0;
    int unit = 0;
    std::cin >> len_arr;
    std::vector<int> pref_sum_arr;
    pref_sum_arr.push_back(0);
    for (int j = 1; j < len_arr + 1; ++j) {
        std::cin >> unit;
        pref_sum_arr.push_back(unit + pref_sum_arr[j-1]);
    }
    for (int j = 1; j < len_arr + 1; ++j) {
        std::cout << pref_sum_arr[j] << ' ';
    }
    return 0;
}