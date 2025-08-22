#include "to_string.hpp"

#include <iostream>
#include <sstream>
#include <string>


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




