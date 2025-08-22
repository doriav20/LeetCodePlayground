#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "utils.hpp"

std::string list_node_to_string(const ListNode* head)
{
    if (head == nullptr)
    {
        return "List is empty";
    }

    std::ostringstream oss;

    while (head->next)
    {
        oss << head->val << " --> ";
        head = head->next;
    }
    oss << head->val;

    return oss.str();
}

std::string _tree_node_to_string(const TreeNode* root)
{
    if (root == nullptr)
    {
        return "";
    }

    std::ostringstream oss;

    oss << _tree_node_to_string(root->left);
    oss << root->val << ' ';
    oss << _tree_node_to_string(root->right);

    return oss.str();
}

std::string tree_node_to_string(const TreeNode* root)
{
    if (root == nullptr)
    {
        return "Tree is empty";
    }

    return _tree_node_to_string(root);
}

ListNode* create_list_node_from_vector(const std::vector<int>& vec)
{
    ListNode* head = nullptr;
    ListNode* pos = nullptr;
    for (int num : vec)
    {
        if (head == nullptr)
        {
            head = pos = new ListNode(num);
            continue;
        }
        pos->next = new ListNode(num);
        pos = pos->next;
    }
    return head;
}

TreeNode* _create_tree_node_from_vector(const std::vector<int>& vec, int rootIndex)
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
    root->left = _create_tree_node_from_vector(vec, 2 * rootIndex + 1);
    root->right = _create_tree_node_from_vector(vec, 2 * rootIndex + 2);
    return root;
}

TreeNode* create_tree_node_from_vector(const std::vector<int>& vec)
{
    if (vec.empty())
    {
        return nullptr;
    }
    return _create_tree_node_from_vector(vec, 0);
}
