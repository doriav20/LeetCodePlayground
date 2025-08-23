#pragma once

#include <string>

#include "concepts/concepts.hpp"

template<Vector T>
    requires Streamable<typename bare_t<T>::value_type>
std::string to_string(const T& vec);

template<Matrix T>
    requires Streamable<typename bare_t<typename bare_t<T>::value_type>::value_type>
std::string to_string(const T& mat);

template<Stack T>
    requires Streamable<typename bare_t<T>::value_type>
std::string to_string(const T& stk);

template<Streamable T>
std::string to_string(const T& value);

template<ListNodePtr T>
std::string to_string(const T& head);

template<TreeNodePtr T>
std::string to_string(const T& root);

#include "to_string.tpp"
