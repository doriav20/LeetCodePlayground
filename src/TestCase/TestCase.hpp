#pragma once

#include <iostream>
#include <tuple>
#include <utility>

#include "concepts/concepts.hpp"

template<typename ResultType, typename... Args>
class TestCase
{
private:
    std::tuple<bare_t<Args>...> m_args;
    bare_t<ResultType> m_expected;

public:
    TestCase(bare_t<Args>... args, bare_t<ResultType> expected);

    bool run(ResultType (*func)(Args...), const bool verbose = true);
};

template<typename... Args>
class TestCase<void, Args...>
{
private:
    std::tuple<bare_t<Args>...> m_args;

public:
    TestCase(bare_t<Args>... args);

    bool run(void (*func)(Args...), const bool verbose = true);
};

#include "TestCase.tpp"
