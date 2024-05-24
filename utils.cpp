#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include "utils.h"


std::string vector_to_string(const std::vector<int>& vec) {
    if (vec.empty()) {
        return "[]";
    }
    std::string s;
    s += "[";
    s += std::to_string(vec[0]);
    for (int i = 1; i < vec.size(); i++) {
        s += ",";
        s += std::to_string(vec[i]);
    }
    s += "]";
    return s;
}

std::string vector_to_string(const std::vector<std::string>& vec) {
    if (vec.empty()) {
        return "[]";
    }
    std::string s;
    s += "[";
    s += vec[0];
    for (int i = 1; i < vec.size(); i++) {
        s += ",";
        s += vec[i];
    }
    s += "]";
    return s;
}

std::string vector_to_string(const std::vector<char>& vec) {
    if (vec.empty()) {
        return "[]";
    }
    std::string s;
    s += "[";
    s += vec[0];
    for (int i = 1; i < vec.size(); i++) {
        s += ",";
        s += vec[i];
    }
    s += "]";
    return s;
}

std::string matrix_to_string(const std::vector<std::vector<int>>& mat) {
    if (mat.empty()) {
        return "[]";
    }
    std::string s;
    s += "[";
    s += vector_to_string(mat[0]);
    for (int i = 1; i < mat.size(); i++) {
        s += ",";
        s += vector_to_string(mat[i]);
    }
    s += "]";
    return s;
}

std::string matrix_to_string(const std::vector<std::vector<std::string>>& mat) {
    if (mat.empty()) {
        return "[]";
    }
    std::string s;
    s += "[";
    s += vector_to_string(mat[0]);
    for (int i = 1; i < mat.size(); i++) {
        s += ",";
        s += vector_to_string(mat[i]);
    }
    s += "]";
    return s;
}

std::string matrix_to_string(const std::vector<std::vector<char>>& mat) {
    if (mat.empty()) {
        return "[]";
    }
    std::string s;
    s += "[";
    s += vector_to_string(mat[0]);
    for (int i = 1; i < mat.size(); i++) {
        s += ",";
        s += vector_to_string(mat[i]);
    }
    s += "]";
    return s;
}

std::string stack_to_string(std::stack<int> stk) {
    if (stk.empty()) {
        return "[]";
    }
    std::string s;
    s += std::to_string(stk.top());
    stk.pop();
    while (!stk.empty()) {
        s = "," + s;
        s = std::to_string(stk.top()) + s;
        stk.pop();
    }
    s = "[" + s + "]";
    return s;
}

std::string stack_to_string(std::stack<std::string> stk) {
    if (stk.empty()) {
        return "[]";
    }
    std::string s;
    s += stk.top();
    stk.pop();
    while (!stk.empty()) {
        s = "," + s;
        s = stk.top() + s;
        stk.pop();
    }
    s = "[" + s + "]";
    return s;
}

std::string stack_to_string(std::stack<char> stk) {
    if (stk.empty()) {
        return "[]";
    }
    std::string s;
    s += stk.top();
    stk.pop();
    while (!stk.empty()) {
        s = "," + s;
        s = stk.top() + s;
        stk.pop();
    }
    s = "[" + s + "]";
    return s;
}

std::string list_node_to_string(ListNode* head) {
    if (head == nullptr) {
        return "List is empty";
    }
    std::string s;
    while (head->next) {
        s += std::to_string(head->val);
        s += " --> ";
        head = head->next;
    }
    s += std::to_string(head->val);
    return s;
}

std::string _tree_node_to_string(TreeNode* root) {
    if (root == nullptr) return "";
    std::string s;
    s += _tree_node_to_string(root->left);
    s += std::to_string(root->val) + " ";
    s += _tree_node_to_string(root->right);
    return s;
}

std::string tree_node_to_string(TreeNode* root) {
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
