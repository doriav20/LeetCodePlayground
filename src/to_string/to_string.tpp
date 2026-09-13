#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <ranges>
#include <string_view>

#include "concepts/concepts.hpp"

namespace _internal
{
template<std::ranges::input_range R>
std::string join_items(const R& items)
{
    if (std::ranges::empty(items))
    {
        return "[]";
    }

    const std::string joined = items
                               | std::views::transform([](const auto& item) { return to_string(item); })
                               | std::views::join_with(std::string_view(", "))
                               | std::ranges::to<std::string>();
    return "[ " + joined + " ]";
}
}

template<Vector T>
std::string to_string(const T& vec)
{
    return _internal::join_items(vec);
}

template<Stack T>
std::string to_string(const T& stk)
{
    std::stack<typename bare_t<T>::value_type> stk_copy = stk;
    std::vector<typename bare_t<T>::value_type> items;
    while (!stk_copy.empty())
    {
        items.push_back(stk_copy.top());
        stk_copy.pop();
    }

    return _internal::join_items(items);
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
std::string to_string(const T& root)
{
    if (root == nullptr)
    {
        return "Tree is empty";
    }

    std::vector<std::string> values;
    std::queue<T> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        T node = nodes.front();
        nodes.pop();

        if (node == nullptr)
        {
            values.emplace_back("null");
            continue;
        }
        values.push_back(std::to_string(node->val));
        nodes.push(node->left);
        nodes.push(node->right);
    }

    while (values.back() == "null")
    {
        values.pop_back();
    }

    return _internal::join_items(values);
}

template<Streamable T>
std::string to_string(const T& value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}
