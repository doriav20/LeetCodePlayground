#pragma once

#include <iostream>
#include <limits>
#include <stack>
#include <vector>

constexpr int NULL_NODE = std::numeric_limits<int>::min();

template<typename T>
std::string vector_to_string(const std::vector<T>& vec);

template<typename T>
std::string matrix_to_string(const std::vector<std::vector<T>>& mat);

template<typename T>
std::string stack_to_string(const std::stack<T>& stk);

#include "utils.tpp"

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::string list_node_to_string(const ListNode* head);

std::string tree_node_to_string(const TreeNode* root);

ListNode* create_list_node_from_vector(const std::vector<int>& vec);

TreeNode* create_tree_node_from_vector(const std::vector<int>& vec);
