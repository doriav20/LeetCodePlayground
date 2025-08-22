#pragma once

#include <limits>
#include <vector>

constexpr int NULL_NODE = std::numeric_limits<int>::min();

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* create_tree_node_from_vector(const std::vector<int>& vec);
