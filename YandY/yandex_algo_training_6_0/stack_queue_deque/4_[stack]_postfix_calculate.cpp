#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

int main() {
    std::string postfix_expr;
    std::vector<int> stack;
    std::getline(std::cin, postfix_expr);
    postfix_expr.erase(std::remove(postfix_expr.begin(), postfix_expr.end(), ' '), postfix_expr.end()); // чистим пробелы, ремув переставляет в конец и вернёт иттератор откуда читску начинать
    for (int j = 0; j < postfix_expr.size(); ++j) {
        if (std::isdigit(postfix_expr[j])) stack.push_back(postfix_expr[j] - '0'); // интерпретируем как число, а не как ASCII
        else if (postfix_expr[j] == '+') {
            int pushed = stack[stack.size() - 2] + stack[stack.size()- 1];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(pushed);
        }
        else if (postfix_expr[j] == '*') {
            int pushed = stack[stack.size() - 2] * stack[stack.size()- 1];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(pushed);
        }
        else if (postfix_expr[j] == '-') {
            int pushed = stack[stack.size() - 2] - stack[stack.size()- 1];
            stack.pop_back();
            stack.pop_back();
            stack.push_back(pushed);
        }
    }
    std::cout << stack.back() << std::endl;
    return 0;
}