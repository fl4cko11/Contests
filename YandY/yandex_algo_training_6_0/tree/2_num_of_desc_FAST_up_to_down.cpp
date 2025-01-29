#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

// Рекурсия до бездетных и раскрутка от них до вершины запуска с +1 (тк нет корня, запускаемся от всех вершин)

int make_height(std::unordered_map<std::string, std::vector<std::string>> &parent_vec_of_child, std::unordered_map<std::string, int> &height, std::string cur_parent) {
    if (height[cur_parent] == -1) { // если ещё не заходили
        height[cur_parent] = 0; // помечаем, что зашли
        if (!parent_vec_of_child[cur_parent].empty()) {
            int j = 0;
            while (j < parent_vec_of_child[cur_parent].size()) {
                height[cur_parent] += 1 + make_height(parent_vec_of_child, height, parent_vec_of_child[cur_parent][j]); // свой ребёнок (1) + все его дети (рекурсия)
                ++j;
            }
            return height[cur_parent];
        }
        return height[cur_parent];
    }
    else return height[cur_parent]; // если уже считали возвращаем его число потомков
}

int main() {
    int num_of_input = 0;
    std::cin >> num_of_input;
    std::unordered_map<std::string, std::vector<std::string>> parent_vec_of_child;
    std::unordered_map<std::string, int> height;
    std::string child;
    std::string parent;
    for (int j = 0; j < num_of_input - 1; ++j) {
        std::cin >> child >> parent;
        parent_vec_of_child[parent].push_back(child);
        height[parent] = -1; // чтобы корень тоже был
        height[child] = -1;
    }

    // Сформируем высоты -----------------------------------------------------------------------
    std::unordered_map<std::string, std::vector<std::string>> parent_vec_of_child_for_func = parent_vec_of_child; // почему-то функция make height влияет на иттерацию по элементам...
    std::unordered_map<std::string, std::vector<std::string>> &p_ch_v_ref = parent_vec_of_child_for_func;
    std::unordered_map<std::string, int> &height_ref = height;
    for (const auto& pair : parent_vec_of_child) { // иттерируем по парам словаря, а именно по ключам = РОДИТЕЛЯМ
        make_height(p_ch_v_ref, height_ref, pair.first);
    }
    // -----------------------------------------------------------------------------------------

    // Для вывода отсортируем по алфавиту --------------------------------------------------------------------------------
    std::vector<std::pair<std::string, int>> vector_pair_person_num_child(height.begin(), height.end()); // вектор с парами создаём
    std::sort(vector_pair_person_num_child.begin(), vector_pair_person_num_child.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; // сортировка по АЛФАВИТУ
    });
    for (const auto& pair : vector_pair_person_num_child) { // выводим
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    // -------------------------------------------------------------------------------------------------------------------

    return 0;
}