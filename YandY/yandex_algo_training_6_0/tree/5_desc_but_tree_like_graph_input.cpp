#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

// Рекурсия до бездетных и раскрутка от них до вершины запуска с +1

int make_height(std::unordered_map<int, std::vector<int>> &tree, std::unordered_map<int, int> &height, int cur_node) {
    height[cur_node] = 0; // при заходе помечаем, что были в вершине
    for (int j = 0; j < tree[cur_node].size(); ++j) { // не проверяю пустоту списка, тк при таком вводе очев всегда не пустой (иначе есть обособленная вершина !?) 
        if (height[tree[cur_node][j]] == -1) { // идём только в те, которые ещё не посетили
            height[cur_node] += 1 + make_height(tree, height, tree[cur_node][j]);
        }
    }
    return height[cur_node];
}


int main() {
    int num_of_input = 0;
    std::cin >> num_of_input;
    std::unordered_map<int, std::vector<int>> tree; // хеш-таблица: ключ (вершина) - значение (список куда можем добраться из неё)
    std::unordered_map<int, int> height;
    int node1;
    int node2;
    for (int j = 0; j < num_of_input - 1; ++j) {
        std::cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);        
        height[node1] = -1; // маркер, что ещё не были в вершине
        height[node2] = -1;
    }

    // Сформируем высоты -----------------------------------------------------------------------
    std::unordered_map<int, std::vector<int>> &tree_ref = tree;
    std::unordered_map<int, int> &height_ref = height;
    make_height(tree_ref, height_ref, 1); // по условию за 1 подвешено дерево
    // -----------------------------------------------------------------------------------------

    // Вывод (вектор, чтобы корректный вывод был...) -----------------------------------------------------------------------------------
    std::vector<int> values;
    for (int j = 0; j < height.size() + 1; ++j) { // чтобы вектор по индексам построить, изнач его нулями загружаем
        values.push_back(0);
    }
    for (const auto& pair : height) {
        values[pair.first] = pair.second + 1; // +1, так как себя тоже учитываем
    }
    for (int j = 1; j < values.size(); ++j) {
        std::cout << values[j] << " ";
    }
    // -----------------------------------------------------------------------------------------

    return 0;
}