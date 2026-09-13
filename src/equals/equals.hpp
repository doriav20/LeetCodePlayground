#pragma once

#include "concepts/concepts.hpp"

template<typename T>
bool are_equal(const T& lhs, const T& rhs);

template<Vector T>
bool are_equal(const T& lhs, const T& rhs);

template<ListNodePtr T>
bool are_equal(const T& lhs, const T& rhs);

template<TreeNodePtr T>
bool are_equal(const T& lhs, const T& rhs);

#include "equals.tpp"
