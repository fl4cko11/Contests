#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

// Рекурсия до корня, запускаясь от всех вершин и с каждым заходом в конкретную вершину +1 к её высоте,
// тк в конкретную вершину попадём количество раз равное числу его детей при таком обходе

void go_to_root_h(std::unordered_map<std::string, std::string> &child_parent, std::unordered_map<std::string, int> &height, std::string child) {
    ++height[child]; // с каждым заходом в вершину +1
    if (child_parent.find(child) == child_parent.end()) { // словили корень => конец рекурсии
        return;
    }
    else {
        go_to_root_h(child_parent, height, child_parent[child]);
        return;
    }
}

int main() {
    int num_of_input = 0;
    std::cin >> num_of_input;
    std::unordered_map<std::string, std::string> child_parent;
    std::unordered_map<std::string, int> height;
    std::string child;
    std::string parent;
    for (int j = 0; j < num_of_input - 1; ++j) {
        std::cin >> child >> parent;
        child_parent[child] = parent;
        height[child] = -1;
    }

    // Сформируем высоты -------------------------------------------------
    std::unordered_map<std::string, std::string> &ch_p_ref = child_parent;
    std::unordered_map<std::string, int> &height_ref = height;
    for (const auto& pair : child_parent) { // иттерируем по парам словаря, а именно по ключам = детям
        go_to_root_h(ch_p_ref, height_ref, pair.first);
    }
    // -------------------------------------------------------------------

    // Для вывода отсортируем по алфавиту ---------------------------------------
    std::vector<std::pair<std::string, int>> elems(height.begin(), height.end());
    std::sort(elems.begin(), elems.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; // сортировка по ключам
    });
    for (const auto& pair : elems) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    // --------------------------------------------------------------------------

    return 0;
}