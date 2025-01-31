#include <unordered_set>
#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>

// Пройдём по потомкам A собрав их в множестве, а потом пройдёмся от B проверяя каждый раз есть ли текущий потомок в множестве

void make_ancestors_child(std::unordered_map<std::string, std::string> &child_parent, std::unordered_set<std::string> &ancestors_node, std::string cur_child) {
    if (child_parent.find(cur_child) != child_parent.end()) { // если есть предки
        ancestors_node.insert(child_parent[cur_child]); // добавляем родителя текущей и от него запускаемся
        make_ancestors_child(child_parent, ancestors_node, child_parent[cur_child]);
    }
    return; // если нет предков то разворачиваемся
}

std::string nearest_anc_child1_and_child2 (std::unordered_map<std::string, std::string> &child_parent, std::unordered_set<std::string> &ancestors_child1, std::string cur_ancestor_child2) {
    if (ancestors_child1.find(cur_ancestor_child2) != ancestors_child1.end()) return cur_ancestor_child2; // с каждым заходом ищем текущего предка child2 в предках child1; если нашли то его возвращаем, если нет ищем дальше
    if (child_parent.find(cur_ancestor_child2) != child_parent.end()) { // если есть предки ищем дальше
        return nearest_anc_child1_and_child2(child_parent, ancestors_child1, child_parent[cur_ancestor_child2]); // если нашли то дальше разворачиваемся с тру
    }
    return "NO"; // если нет предков и не нашли то разворачиваемся с "NO"
}

int main() {
    std::ifstream input_file("input.txt");
    int num_of_input = 0;
    input_file >> num_of_input;
    std::unordered_map<std::string, std::string> child_parent;
    std::string child;
    std::string parent;
    for (int j = 0; j < num_of_input - 1; ++j) {
        input_file >> child >> parent;
        child_parent[child] = parent;
    }

    std::unordered_map<std::string, std::string> &ch_p_ref = child_parent;

    while (!input_file.eof()) {
        std::string child_A;
        std::string child_B;
        std::unordered_set<std::string> ancestors_A; // каждый раз создаём под запрос своё множество предков
        std::unordered_set<std::string> &ancestors_A_ref = ancestors_A;
        input_file >> child_A >> child_B;
        ancestors_A.insert(child_A); // по условию сам себе предок
        make_ancestors_child(ch_p_ref, ancestors_A_ref, child_A);
        std::cout << nearest_anc_child1_and_child2(ch_p_ref, ancestors_A_ref, child_B) << std::endl;
    } 

    return 0;
}