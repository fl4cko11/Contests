#include <iostream>
#include <string>

// стек позволяет в ревёрснутом виде проанализировать => идеально для правила расставления скобок

int main() {
    std::string input_string;
    std::string stack_string;
    std::cin >> input_string;
    for (int j = 0; j < input_string.size(); ++j) {
        if (input_string[j] == '(' || input_string[j] == '[' || input_string[j] == '{') {
            stack_string.push_back(input_string[j]);
        }
        else if (input_string[j] == ')' || input_string[j] == ']' || input_string[j] == '}') {
            if (stack_string.size() != 0) { // потенциально есть пара
                if (input_string[j] == ')' && stack_string.back() == '(') stack_string.pop_back();
                else if (input_string[j] == ']' && stack_string.back() == '[') stack_string.pop_back();
                else if (input_string[j] == '}' && stack_string.back() == '{') stack_string.pop_back();
                else {
                    std::cout << "no" << std::endl; // не корректная
                    return 0;
                }
            }
            else { // даже пары нету
                std::cout << "no" << std::endl;
                return 0;
            }
        }
        else { // не скобка
            std::cout << "no" << std::endl;
            return 0;
        }
    }
    if (stack_string.size() == 0) { // если после всех пар, стек опустел (= всем пара), то гуд
        std::cout << "yes" << std::endl;
        return 0;
    }
    else {
        std::cout << "no" << std::endl;
        return 0;
    }
}