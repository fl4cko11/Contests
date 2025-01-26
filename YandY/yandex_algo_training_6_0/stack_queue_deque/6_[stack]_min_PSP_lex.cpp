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
    int vacant_len = (need_len_str - bracket_s_seq.size() - stack_string.size()) / 2; // вакантная <=> длина на которой можно самим строить (стек, т.к. то, что в стеке - ждёт пары)

    while (stack_string.size() != 0) { // если в стеке ожидают закрытия, смотрим на цены и наличие вакантного места
        if (stack_string.back() == '(') {
            if ( (br_attitude.find(')') < br_attitude.find('(') && br_attitude.find(')') < br_attitude.find('[')) || vacant_len == 0 ) { // если дешевле закрыть или нет, но нет возможности строить, то закрываеми попаем
                ans_str.push_back(')');
                stack_string.pop_back();
            }
            else { // если дешевле строиться, то строим самую дешёвую, уменьшая вакантное место и пушимся в ожидание пары
                if (br_attitude.find('(') < br_attitude.find('[')) {
                    ans_str.push_back('(');
                    stack_string.push_back('(');
                    --vacant_len;
                }
                else {
                    ans_str.push_back('[');
                    stack_string.push_back('[');
                    --vacant_len;
                }
            }
        }
        else {
            if ( (br_attitude.find(']') < br_attitude.find('(') && br_attitude.find(']') < br_attitude.find('[')) || vacant_len == 0 ) { // аналогично для [
                ans_str.push_back(']');
                stack_string.pop_back();
            }
            else {
                if (br_attitude.find('(') < br_attitude.find('[')) {
                    ans_str.push_back('(');
                    stack_string.push_back('(');
                    --vacant_len;
                }
                else {
                    ans_str.push_back('[');
                    stack_string.push_back('[');
                    --vacant_len;
                }
            }
        }
    }

    if (vacant_len != 0) {
        for (int j = 0; j < vacant_len; ++j) {
            ans_str.push_back(br_attitude[first_open_indx]);
        }
        for (int j = 0; j < vacant_len; ++j) {
            if (br_attitude[first_open_indx] == '(') {
                ans_str.push_back(')');
            }
            else ans_str.push_back(']');        
        }
    }

    std::cout << ans_str << std::endl;
    return 0;
}