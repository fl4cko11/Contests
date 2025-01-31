#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

// Список детей позволяет до корня дойти => Рекурсия до корня и её раскрутка с +1 от него до вершины запуска

int go_to_root(std::unordered_map<std::string, std::string> &child_parent, std::unordered_map<std::string, int> &dist, std::string child) {
    if (dist[child] == -1) { // если ещё не обрабатывали
        if (child_parent.find(child) == child_parent.end()) { // словили корень и раскручиваемся от него
            dist[child] = 0;
            return 0;
        }
        else {
            dist[child] = 1 + go_to_root(child_parent, dist, child_parent[child]);
            return dist[child];
        }
    }
    else return dist[child]; // если уже обработана, то возвращаем её подсичтанную дистанцию
}

int main() {
    int num_of_input = 0;
    std::cin >> num_of_input;
    std::unordered_map<std::string, std::string> child_parent;
    std::unordered_map<std::string, int> dist;
    std::string child;
    std::string parent;
    for (int j = 0; j < num_of_input - 1; ++j) {
        std::cin >> child >> parent;
        child_parent[child] = parent;
        dist[child] = -1;
    }

    // Сформируем дистанции до корня -------------------------------------
    std::unordered_map<std::string, std::string> &ch_p_ref = child_parent;
    std::unordered_map<std::string, int> &dist_ref = dist;
    for (const auto& pair : child_parent) { // иттерируем по парам словаря, а именно по ключам = детям
        go_to_root(ch_p_ref, dist_ref, pair.first);
    }
    // -------------------------------------------------------------------

    // Для вывода отсортируем по алфавиту -----------------------------------
    std::vector<std::pair<std::string, int>> elems(dist.begin(), dist.end()); // вектор с парами
    std::sort(elems.begin(), elems.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; // сортировка по ключам
    });
    for (const auto& pair : elems) { // вывод
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    // -----------------------------------------------------------------------

    return 0;
}