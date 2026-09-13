#pragma once

#include <string>

#include "concepts/concepts.hpp"

template<Vector T>
std::string to_string(const T& vec);

template<Stack T>
std::string to_string(const T& stk);

template<Streamable T>
std::string to_string(const T& value);

template<ListNodePtr T>
std::string to_string(const T& head);

template<TreeNodePtr T>
std::string to_string(const T& root);

#include "to_string.tpp"
