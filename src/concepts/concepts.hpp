#pragma once

#include <ostream>
#include <vector>
#include <stack>
#include <type_traits>

#include "data_structures/ListNode/ListNode.hpp"
#include "data_structures/TreeNode/TreeNode.hpp"

template<typename T>
using bare_t = std::remove_cvref_t<T>;

template<typename T>
concept Streamable = requires(std::ostream& os, const T& v)
{
    { os << v } -> std::same_as<std::ostream&>;
};

template<typename T>
concept Vector = std::same_as<bare_t<T>, std::vector<typename bare_t<T>::value_type>>;

template<typename T>
concept Matrix = Vector<T> && Vector<typename bare_t<T>::value_type>;

template<typename T>
concept Stack = std::same_as<bare_t<T>, std::stack<typename bare_t<T>::value_type>>;

template<typename T>
concept ListNodePtr = std::same_as<std::remove_const_t<std::remove_pointer_t<bare_t<T>>>, ListNode> &&
                      std::is_pointer_v<bare_t<T>> &&
                      Streamable<T>;

template<typename T>
concept TreeNodePtr = std::same_as<std::remove_const_t<std::remove_pointer_t<bare_t<T>>>, TreeNode> &&
                      std::is_pointer_v<bare_t<T>> &&
                      Streamable<T>;
