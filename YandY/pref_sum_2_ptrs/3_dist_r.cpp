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

    int l = 0, r = 0;
    while (r < len_arr) {
        if (arr[r] - arr[l] > sum_to_find) { // если больше левый двигаем (правый остаётся из монотонности)
            count += len_arr - r;
            ++l;
        } 
        else {
            ++r; // если меньше правый двигаем = ищем
        }
    }
    std::cout << count << std::endl;
    return 0;
}