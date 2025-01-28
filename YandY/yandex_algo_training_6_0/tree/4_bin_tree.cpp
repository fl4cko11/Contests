#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

struct YandY_node {
    YandY_node *left;
    YandY_node *right;
    YandY_node *parent;
    int data;
    int depth;

    YandY_node(): left(nullptr), right(nullptr), parent(nullptr), data(-666), depth(0) {}
};

class YandY_bin_tree {

private:

    YandY_node root;

    std::string ADD(int data, YandY_node *cur_node) {
        if (data > cur_node->data) {
            if (cur_node->right != nullptr) return ADD(data, cur_node->right); // обязательно ретёрны, чтобы протащить ответ
            else {
                YandY_node *new_node = new YandY_node;
                cur_node->right = new_node;
                new_node->parent = cur_node;
                new_node->data = data;
                new_node->depth = cur_node->depth + 1;
                return "DONE";
            }
        }
        else if (data < cur_node->data) {
            if (cur_node->left != nullptr) return ADD(data, cur_node->left);
            else {
                YandY_node *new_node = new YandY_node;
                cur_node->left = new_node;
                new_node->parent = cur_node;
                new_node->data = data;
                new_node->depth = cur_node->depth + 1;
                return "DONE";                
            }
        }
        else return "ALREADY";
    }

    std::string SEARCH(int data, YandY_node *cur_node) {
        if (data == cur_node->data) return "YES";
        else if (data > cur_node->data && cur_node->right != nullptr) return SEARCH(data, cur_node->right); // обязательно ретёрны, чтобы протащить ответ
        else if (data < cur_node->data && cur_node->left != nullptr) return SEARCH(data, cur_node->left);

        return "NO";
    }

    void PRINTTREE(YandY_node *cur_node) {
        for (int j = 0; j < cur_node->depth - 1; ++j) { // -1 из-за отростка в виде 0го корня (издержки убогих тестов системы)
            std::cout << ".";
        }
        if (cur_node->data != -666) std::cout << cur_node->data << std::endl; // фиктивный корень не пишем

        if (cur_node->left != nullptr) PRINTTREE(cur_node->left);
        if (cur_node->right != nullptr) PRINTTREE(cur_node->right);

        return;
    }

    void clean_memory(YandY_node *cur_node) {
        if (cur_node->left != nullptr) clean_memory(cur_node->left);
        if (cur_node->right != nullptr) clean_memory(cur_node->right);
        if (cur_node != &root) cur_node;
        return;
    }

public: 
    YandY_bin_tree(): root(){}

    std::string ADD(int data) {
        return ADD(data, &root);
    }

    std::string SEARCH(int data) {
        return SEARCH(data, &root);
    }

    void PRINTTREE() {
        PRINTTREE(&root);
    }

    ~YandY_bin_tree() {
        clean_memory(&root);
    }
};

int main() {
    std::fstream input_file("input.txt");
    YandY_bin_tree tree{}; // корень по умолчанию будет фиктивным, тк натуральные только в инпуте
    while (!input_file.eof()) {
        std::string command_line;
        std::getline(input_file, command_line);
        std::stringstream command_line_ss (command_line);
        std::string command_part;
        int argument_part;
        command_line_ss >> command_part;
        if (command_part == "PRINTTREE") { // без проверок по условию
            tree.PRINTTREE();
        }
        else if (command_part == "ADD") {
            command_line_ss >> argument_part;
            std::cout << tree.ADD(argument_part) << std::endl;
        }
        else if (command_part == "SEARCH") {
            command_line_ss >> argument_part;
            std::cout << tree.SEARCH(argument_part) << std::endl;
        }
    }

    return 0;
}