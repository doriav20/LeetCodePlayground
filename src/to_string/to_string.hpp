#pragma once

#include <stack>
#include <string>
#include <vector>

#include "data_structures/ListNode/ListNode.hpp"
#include "data_structures/TreeNode/TreeNode.hpp"


template<typename T>
std::string vector_to_string(const std::vector<T>& vec);

template<typename T>
std::string matrix_to_string(const std::vector<std::vector<T> >& mat);

template<typename T>
std::string stack_to_string(const std::stack<T>& stk);

std::string list_node_to_string(const ListNode* head);

std::string tree_node_to_string(const TreeNode* root);

#include "to_string.tpp"
