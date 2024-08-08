#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "utils.h"

template<typename T>
std::string vector_to_string(const std::vector<T>& vec) {
    if (vec.empty()) {
        return "[]";
    }

    std::ostringstream oss;

    oss << "[ ";

    oss << vec[0];
    for (int i = 1; i < vec.size(); i++) {
        oss << ", " << vec[i];
    }

    oss << " ]";

    return oss.str();
}

template std::string vector_to_string<int>(const std::vector<int>& vec);

template std::string vector_to_string<std::string>(const std::vector<std::string>& vec);

template std::string vector_to_string<char>(const std::vector<char>& vec);

template<typename T>
std::string matrix_to_string(const std::vector<std::vector<T>>& mat) {
    if (mat.empty()) {
        return "[]";
    }

    std::ostringstream oss;

    oss << "[ ";

    oss << vector_to_string(mat[0]);
    for (int i = 1; i < mat.size(); i++) {
        oss << ", " << vector_to_string(mat[i]);
    }

    oss << " ]";

    return oss.str();
}

template std::string matrix_to_string<int>(const std::vector<std::vector<int>>& vec);

template std::string matrix_to_string<std::string>(const std::vector<std::vector<std::string>>& vec);

template std::string matrix_to_string<char>(const std::vector<std::vector<char>>& vec);

template<typename T>
std::string stack_to_string(const std::stack<T>& stk) {
    if (stk.empty()) {
        return "[]";
    }

    std::stack<T> stk_copy = stk;
    std::queue<T> q;
    while (!stk_copy.empty()) {
        q.push(stk_copy.top());
        stk_copy.pop();
    }

    std::ostringstream oss;

    oss << "[ ";

    oss << q.front();
    q.pop();

    while (!q.empty()) {
        oss << ", " << q.front();
        q.pop();
    }

    oss << " ]";

    return oss.str();
}

template std::string stack_to_string<int>(const std::stack<int>& stk);

template std::string stack_to_string<std::string>(const std::stack<std::string>& stk);

template std::string stack_to_string<char>(const std::stack<char>& stk);

std::string list_node_to_string(const ListNode* head) {
    if (head == nullptr) {
        return "List is empty";
    }

    std::ostringstream oss;

    while (head->next) {
        oss << head->val << " --> ";
        head = head->next;
    }
    oss << head->val;

    return oss.str();
}

std::string _tree_node_to_string(const TreeNode* root) {
    if (root == nullptr) return "";

    std::ostringstream oss;

    oss << _tree_node_to_string(root->left);
    oss << root->val << ' ';
    oss << _tree_node_to_string(root->right);

    return oss.str();
}

std::string tree_node_to_string(const TreeNode* root) {
    if (root == nullptr) {
        return "Tree is empty";
    }

    return _tree_node_to_string(root);
}

ListNode* create_list_node_from_vector(const std::vector<int>& vec) {
    ListNode* head = nullptr;
    ListNode* pos = nullptr;
    for (int num: vec) {
        if (head == nullptr) {
            head = pos = new ListNode(num);
            continue;
        }
        pos->next = new ListNode(num);
        pos = pos->next;
    }
    return head;
}

TreeNode* _create_tree_node_from_vector(const std::vector<int>& vec, int rootIndex) {
    if (rootIndex >= vec.size()) return nullptr;
    int val = vec[rootIndex];
    if (val == NULL_NODE) return nullptr;
    auto root = new TreeNode(val);
    root->left = _create_tree_node_from_vector(vec, 2 * rootIndex + 1);
    root->right = _create_tree_node_from_vector(vec, 2 * rootIndex + 2);
    return root;
}

TreeNode* create_tree_node_from_vector(const std::vector<int>& vec) {
    if (vec.empty()) return nullptr;
    return _create_tree_node_from_vector(vec, 0);
}
