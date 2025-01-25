#include <iostream>
#include <vector>

int main() {
    int len_arr = 0;
    std::cin >> len_arr;
    std::vector<int> arr;
    std::vector<int> pref_sum_arr;
    int unit = 0;
    pref_sum_arr.push_back(0);
    for (int j = 0; j < len_arr; ++j) {
        std::cin >> unit;
        arr.push_back(unit);
        if (j == 0) {
            pref_sum_arr.push_back(unit);
        }
        if (j != 0) {
            pref_sum_arr.push_back(unit + pref_sum_arr[j]);
        }
    }

    int triple_mult = 0;

    for (int j = 1; j < len_arr - 1; ++j) {
        triple_mult = (triple_mult + arr[j] * pref_sum_arr[j] * (pref_sum_arr[len_arr] - pref_sum_arr[j + 1])) % 1000000007;
    }
    std::cout << triple_mult << std::endl;
    return 0;
}