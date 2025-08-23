#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>

#include "concepts/concepts.hpp"

template<Vector T>
    requires Streamable<typename bare_t<T>::value_type>
std::string to_string(const T& vec)
{
    if (vec.empty())
    {
        return "[]";
    }

    std::ostringstream oss;

    oss << "[ ";

    oss << vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        oss << ", " << vec[i];
    }

    oss << " ]";

    return oss.str();
}

template<Matrix T>
    requires Streamable<typename bare_t<typename bare_t<T>::value_type>::value_type>
std::string to_string(const T& mat)
{
    if (mat.empty())
    {
        return "[]";
    }

    std::ostringstream oss;

    oss << "[ ";

    oss << to_string(mat[0]);
    for (int i = 1; i < mat.size(); i++)
    {
        oss << ", " << to_string(mat[i]);
    }

    oss << " ]";

    return oss.str();
}

template<Stack T>
    requires Streamable<typename bare_t<T>::value_type>
std::string to_string(const T& stk)
{
    if (stk.empty())
    {
        return "[]";
    }

    std::stack<typename bare_t<T>::value_type> stk_copy = stk;
    std::queue<typename bare_t<T>::value_type> q;
    while (!stk_copy.empty())
    {
        q.push(stk_copy.top());
        stk_copy.pop();
    }

    std::ostringstream oss;

    oss << "[ ";

    oss << q.front();
    q.pop();

    while (!q.empty())
    {
        oss << ", " << q.front();
        q.pop();
    }

    oss << " ]";

    return oss.str();
}

template<ListNodePtr T>
std::string to_string(const T& head)
{
    if (head == nullptr)
    {
        return "List is empty";
    }

    std::ostringstream oss;

    T pos = head;
    while (pos->next)
    {
        oss << pos->val << " --> ";
        pos = pos->next;
    }
    oss << pos->val;

    return oss.str();
}

template<TreeNodePtr T>
std::string tree_node_to_string_helper(const T& root)
{
    if (root == nullptr)
    {
        return "";
    }

    std::ostringstream oss;

    oss << tree_node_to_string_helper(root->left);
    oss << root->val << ' ';
    oss << tree_node_to_string_helper(root->right);

    return oss.str();
}

template<TreeNodePtr T>
std::string to_string(const T& root)
{
    if (root == nullptr)
    {
        return "Tree is empty";
    }

    return tree_node_to_string_helper(root);
}

template<Streamable T>
std::string to_string(const T& value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}
