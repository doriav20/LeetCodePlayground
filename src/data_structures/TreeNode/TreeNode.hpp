#pragma once

#include <limits>
#include <vector>

constexpr int NULL_NODE = std::numeric_limits<int>::min();

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : TreeNode(0) {}

    TreeNode(const int x) : TreeNode(x, nullptr, nullptr) {}

    TreeNode(const int x, TreeNode* left_ptr, TreeNode* right_ptr) : val(x), left(left_ptr), right(right_ptr) {}
};

TreeNode* create_tree_node_from_vector(const std::vector<int>& vec);
