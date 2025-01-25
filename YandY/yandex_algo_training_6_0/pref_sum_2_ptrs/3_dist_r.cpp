#include <iostream>
#include <vector>

int main() {
    int len_arr = 0;
    int sum_to_find = 0;
    int unit = 0;
    int count = 0;
    std::cin >> len_arr;
    std::cin >> sum_to_find;
    std::vector<int> arr;
    for (int j = 0; j < len_arr; ++j) {
        std::cin >> unit;
        arr.push_back(unit);
    }

    int r = 0;
    for (int l = 0; l < len_arr; ++l) {
        while (arr[r] - arr[l] <= sum_to_find && r < len_arr) {
            ++r;
        }
        count += len_arr - r;
    }
    std::cout << count << std::endl;
    return 0;
}