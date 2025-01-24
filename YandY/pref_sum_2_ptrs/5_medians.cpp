#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int len_arr = 0;
    std::cin >> len_arr;
    std::vector<int> arr;
    int unit = 0;
    for (int j = 0; j < len_arr; ++j) {
        std::cin >> unit;
        arr.push_back(unit);
    }

    std::sort(arr.begin(), arr.end());

    int l = 0, r = 0;
    if (len_arr % 2 != 0) {
        r = l = (len_arr - 1) / 2;
        std::cout << arr[l] << " ";
        --l;
        ++r;
    }
    else {
        l = (len_arr - 1) / 2;
        r = l + 1;
    }

    while (l >= 0 && r <= len_arr - 1) {
        std::cout << arr[l] << " ";
        --l;
        std::cout << arr[r] << " ";
        ++r;
    }
    return 0;
}