#include <iostream>
#include <vector>

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
    for (int l = 0, r = 1; l < len_arr; ++r) {
        if (pref_sum_arr[r] - pref_sum_arr[l] > sum_to_find) { // если на отрезке сумма стала больше, то дальше можно не смотреть для текщуего l
            ++l;
            while (pref_sum_arr[r] - pref_sum_arr[l] > sum_to_find) { // r корректируем так, чтобы начинать с первого момента где < K
                --r;
            }
        }
        if (pref_sum_arr[r] - pref_sum_arr[l] == sum_to_find) { // ловим
            ++l;
            ++count;
        }
        if (r == len_arr) break; // конец
    }
    std::cout << count << std::endl;
    return 0;
}