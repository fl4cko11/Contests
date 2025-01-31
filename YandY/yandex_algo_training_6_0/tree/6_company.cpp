#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

// Идём по фронту вектора, тк он по построению отсортирован, причём за один проход задания до рабочего только один он увольняется
// За проход к накопленному добавляем именно деньги в данном проходе
// При возврате проверяем если список детей пуст, то это работяга и попаем его, причём запрещаем дальше при возвратах попать
// так запускаемся пока список рабочих CEO не опустеет 

int make_money(std::unordered_map<int, std::vector<int>> &parent_child, std::unordered_map<int, int> &money, int cur_node, bool &was_pop) {
    if (parent_child[cur_node].size() != 0) { // если есть работяги в подчинении
        int money_one_worker_chain = 0; // подсчёт денег в цепочке передачи ОДНОГО задания
        money_one_worker_chain = 1 + make_money(parent_child, money, parent_child[cur_node].front(), was_pop); // запускаемся от 1го в векторе = самого маленького номера
        money[cur_node] += money_one_worker_chain;
        if (parent_child[parent_child[cur_node].front()].size() == 0 && was_pop == false) {
            parent_child[cur_node].erase(parent_child[cur_node].begin()); // если нет работников у самого мальенького то попаем его (работяга отработал и уволился)
            was_pop = true; // только один поп за цепочку может быть (работяга)
        }
        return money_one_worker_chain;
    }
    else {
        money[cur_node] += 1;
        return 1;
    }
}

int main() {
    int num_of_nodes = 0;
    std::cin >> num_of_nodes;
    std::unordered_map<int, std::vector<int>> parent_child;
    std::unordered_map<int, int> money;
    int parent = 0;
    for (int j = 0; j < num_of_nodes - 1; ++j) {
        std::cin >> parent;
        parent_child[parent].push_back(j+2); // по условию => уже сразу по возрастанию отсортированы
        money[j+1] = 0;
    }
    money[num_of_nodes] = 0; // последний в цикл не влез

    std::unordered_map<int, std::vector<int>> &parent_child_ref = parent_child;
    std::unordered_map<int, int> &money_ref = money;
    bool was_pop = false;
    bool &was_pop_ref = was_pop;
    while (parent_child[1].size() != 0) { // пока не уволится CEO
        was_pop = false; // с каждым запуском попа пока не было
        make_money(parent_child_ref, money_ref, 1, was_pop_ref); // С 1го запуск по условию
    }
    ++money[1]; // CEO отрабатывает ластовую

    for (int j = 1; j < num_of_nodes + 1; ++j) {
        std::cout << money[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}