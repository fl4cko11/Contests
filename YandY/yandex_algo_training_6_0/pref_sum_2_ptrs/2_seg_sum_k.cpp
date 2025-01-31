#include <iostream>
#include <vector>

// двигаем правый, пока меньше, как только больше сравниваем и при сдвиге левого сравниваем

int main() {
    int len_arr = 0;
    int sum_to_find = 0;
    int unit = 0;
    int count = 0;
    std::cin >> len_arr;
    std::cin >> sum_to_find;
    std::vector<int> pref_sum_arr;
    pref_sum_arr.push_back(0);
    for (int j = 1; j < len_arr + 1; ++j) {
        std::cin >> unit;
        pref_sum_arr.push_back(unit + pref_sum_arr[j-1]);
    }

    int r = 0;
    for (int l = 0; l < len_arr + 1; ++l) {
        if (pref_sum_arr[r] - pref_sum_arr[l] == sum_to_find) ++count;
        while (pref_sum_arr[r] - pref_sum_arr[l] < sum_to_find && r < len_arr + 1) {
            ++r;
        }
        if (pref_sum_arr[r] - pref_sum_arr[l] == sum_to_find) {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return 0;
}