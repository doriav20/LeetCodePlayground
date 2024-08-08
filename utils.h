#ifndef LEETCODEPLAYGROUND_UTILS_H
#define LEETCODEPLAYGROUND_UTILS_H


#include <iostream>
#include <vector>

#define NULL_NODE INT_MIN

template<typename T>
std::string vector_to_string(const std::vector<T>& vec);

template<typename T>
std::string matrix_to_string(const std::vector<std::vector<T>>& mat);

template<typename T>
std::string stack_to_string(const std::stack<T>& stk);

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::string list_node_to_string(ListNode* head);

std::string tree_node_to_string(TreeNode* root);

ListNode* create_list_node_from_vector(const std::vector<int>& vec);

TreeNode* create_tree_node_from_vector(const std::vector<int>& vec);


#endif //LEETCODEPLAYGROUND_UTILS_H
