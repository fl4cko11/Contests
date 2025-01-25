#include <iostream>
#include <vector>
#include <utility>

int main() {
    int len_arr = 0;
    std::cin >> len_arr;
    std::vector<int> arr;
    std::vector<int> move_city;
    std::vector<std::pair<int, int>> stack; // храним (значение, индекс)
    int unit = 0;
    for (int j = 0; j < len_arr; ++j) {
        std::cin >> unit;
        arr.push_back(unit);
        move_city.push_back(-1);
    }

    stack.push_back(std::make_pair(arr[0], 0)); // 1й очев запушится
    for (int j = 1; j < len_arr; ++j) { // двигаясь так по построению находим ближайшие
        while (arr[j] < stack.back().first && stack.size() != 0) { // если справа дешевле, то это ближ меньший
            move_city[stack.back().second] = j; // верхнему на стеке городу в j и попаем
            stack.pop_back();
        }
        stack.push_back(std::make_pair(arr[j], j)); // для этого и для перед ним в стеке будет один ближ (следует из цикла вайл)
    }

    for (int j = 0; j < len_arr; ++j) {
        std::cout << move_city[j] << " ";
    }
    std::cout << std::endl;
    return 0;
}