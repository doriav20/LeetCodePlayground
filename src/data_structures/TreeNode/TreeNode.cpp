#include "TreeNode.hpp"

TreeNode* create_tree_node_from_vector_helper(const std::vector<int>& vec, const size_t rootIndex)
{
    if (rootIndex >= vec.size())
    {
        return nullptr;
    }

    int val = vec[rootIndex];
    if (val == NULL_NODE)
    {
        return nullptr;
    }

    TreeNode* root = new TreeNode(val);
    root->left = create_tree_node_from_vector_helper(vec, 2 * rootIndex + 1);
    root->right = create_tree_node_from_vector_helper(vec, 2 * rootIndex + 2);
    return root;
}

TreeNode* create_tree_node_from_vector(const std::vector<int>& vec)
{
    if (vec.empty())
    {
        return nullptr;
    }
    return create_tree_node_from_vector_helper(vec, 0);
}
