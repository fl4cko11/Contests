#include <iostream>
#include <deque>
#include <vector>

int main() {
    int len_arr = 0;
    int window_size = 0;
    std::cin >> len_arr >> window_size;
    std::vector<int> arr;
    int unit = 0;
    for (int j = 0; j < len_arr; ++j) {
        std::cin >> unit;
        arr.push_back(unit);
    }
    
    int r = 1;
    std::deque<int> deque;
    deque.push_front(arr[0]); // 1й очев зайдёт
    for (int l = 0; l < len_arr; ++l) {
        while(r - l + 1 <= window_size && r < len_arr) { // идём по окнам

            while (arr[r] < deque.back() && deque.size() != 0) deque.pop_back(); // при заходе пока бэк больше и НЕ ПУСТОЙ ДЭК попаем
            
            deque.push_back(arr[r]); // как только встретили больше - пушимся с бэка
            ++r; // двигаемся по правой границе
        }
        
        std::cout << deque.front() << std::endl; // как только просканировали полосу выводим фронт по постр-ю
        if (arr[l] == deque.front()) deque.pop_front(); // если при сдвиге левой границы минимум ушёл, то из дэка его
        if (l == len_arr - window_size) return 0;
    }
    return 0;
}