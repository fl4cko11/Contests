#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int need_len_str = 0;
    std::string br_attitude;
    std::string bracket_s_seq;
    std::cin >> need_len_str;
    std::cin >> br_attitude;
    std::cin >> bracket_s_seq;

    std::string stack_string;

    // Обработаем s: сформируем стек, те в нём будут лежать ожидающие пары скобки (по условию гарантируется сущ ответа => без проверок)
    for (int j = 0; j < bracket_s_seq.size(); ++j) {
        if (bracket_s_seq[j] == '(' || bracket_s_seq[j] == '[') {
            stack_string.push_back(bracket_s_seq[j]);
        }
        else if (bracket_s_seq[j] == ')') stack_string.pop_back();
        else if (bracket_s_seq[j] == ']') stack_string.pop_back();
    }
    // -----------------------------------------------------------

    // Найдём первую открывающую в attitude  
    int first_open_indx = std::min(br_attitude.find('('), br_attitude.find('['));
    // -----------------------------------------------------------

    // Сформируем ответ
    std::string ans_str(bracket_s_seq);
    int vacant_len = need_len_str - bracket_s_seq.size() - stack_string.size(); // вакантная <=> длина на которой можно самим строить (стек, тк то что в стеке ждёт пары)

    if(vacant_len <= 0) { // если нет места для вставки нашей, то просто пары струячим
        while (stack_string.size() != 0) {
            if (stack_string.back() == '(') {
                ans_str.push_back(')');
                stack_string.pop_back();
            }
            else if (stack_string.back() == '[') {
                ans_str.push_back(']');
                stack_string.pop_back();
            }
        }
        std::cout << ans_str << std::endl;
        return 0;
    }

    else {
        if (br_attitude[0] == ')') { // если самая дешёвая ЗАКРЫВАЮЩАЯ и её ждут НА ВЕРХУШКЕ => закрываем пока закрывается; вакантная не поменялаь так -1 от стека и +1 в вакантной
            while (stack_string.size() != 0 && stack_string.back() == '(') {
                ans_str.push_back(')');
                stack_string.pop_back();
            }
        }
        else if (br_attitude[0] == ']') {
            while (stack_string.size() != 0 && stack_string.back() == '[') {
                ans_str.push_back(']');
                stack_string.pop_back();
            }
        }
        for(int j = 0; j < vacant_len / 2; ++j) { // теперь достраиваем НА ВАКАНТНОЙ по самой дешёвой ОТКРЫВАЮЩЕЙ, тк просто так шлёпнуть закрывающую нельзя из-за ПСП
            ans_str.push_back(br_attitude[first_open_indx]);
            if (br_attitude[first_open_indx] == '(') {
                ans_str.push_back(')');
            }
            else ans_str.push_back(']');
        }
        while (stack_string.size() != 0) { // теперь достраиваем до ПСП изначальную
            if (stack_string.back() == '(') {
                ans_str.push_back(')');
                stack_string.pop_back();
            }
            else if (stack_string.back() == '[') {
                ans_str.push_back(']');
                stack_string.pop_back();
            }
        }
        std::cout << ans_str << std::endl;
        return 0;
    }
}