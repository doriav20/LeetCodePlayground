#pragma once

#include <cstddef>
#include <iostream>
#include <tuple>
#include <utility>

template<typename ResultType, typename... Args>
class TestCase
{
private:
    std::tuple<Args...> m_args;
    ResultType m_expected;

public:
    TestCase(const Args... args, const ResultType expected);

    template<size_t... IdxSeq>
    ResultType call_function(std::index_sequence<IdxSeq...>, ResultType (*func)(Args...));

    bool run(ResultType (*func)(Args...), const bool verbose = true);
};

template<typename... Args>
class TestCase<void, Args...>
{
private:
    std::tuple<Args...> m_args;

public:
    TestCase(const Args... args);

    template<size_t... IdxSeq>
    void call_function(std::index_sequence<IdxSeq...>, void (*func)(Args...));

    bool run(void (*func)(Args...), const bool verbose = true);
};

#include "TestCase.tpp"
