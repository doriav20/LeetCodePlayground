#include "TreeNode.hpp"

#include <queue>

TreeNode* create_tree_node_from_vector(const std::vector<int>& vec)
{
    if (vec.empty() || vec[0] == NULL_NODE)
    {
        return nullptr;
    }

    TreeNode* root = new TreeNode(vec[0]);
    std::queue<TreeNode*> parents;
    parents.push(root);

    size_t i = 1;
    while (i < vec.size() && !parents.empty())
    {
        TreeNode* parent = parents.front();
        parents.pop();

        if (vec[i] != NULL_NODE)
        {
            parent->left = new TreeNode(vec[i]);
            parents.push(parent->left);
        }
        i++;

        if (i < vec.size() && vec[i] != NULL_NODE)
        {
            parent->right = new TreeNode(vec[i]);
            parents.push(parent->right);
        }
        i++;
    }
    return root;
}
