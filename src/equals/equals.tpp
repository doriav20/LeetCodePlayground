#include <algorithm>

#include "concepts/concepts.hpp"

template<typename T>
bool are_equal(const T& lhs, const T& rhs)
{
    return lhs == rhs;
}

template<Vector T>
bool are_equal(const T& lhs, const T& rhs)
{
    using Item = typename bare_t<T>::value_type;
    return std::ranges::equal(lhs, rhs, [](const Item& lhs_item, const Item& rhs_item)
    {
        return are_equal(lhs_item, rhs_item);
    });
}

template<ListNodePtr T>
bool are_equal(const T& lhs, const T& rhs)
{
    T lhs_pos = lhs;
    T rhs_pos = rhs;
    while (lhs_pos != nullptr && rhs_pos != nullptr)
    {
        if (lhs_pos->val != rhs_pos->val)
        {
            return false;
        }
        lhs_pos = lhs_pos->next;
        rhs_pos = rhs_pos->next;
    }
    return lhs_pos == rhs_pos;
}

template<TreeNodePtr T>
bool are_equal(const T& lhs, const T& rhs)
{
    if (lhs == nullptr || rhs == nullptr)
    {
        return lhs == rhs;
    }
    return lhs->val == rhs->val && are_equal(lhs->left, rhs->left) && are_equal(lhs->right, rhs->right);
}
