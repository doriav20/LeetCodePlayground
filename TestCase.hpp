#pragma once

template<typename ResultType, typename... Args>
class TestCase
{
private:
    std::tuple<Args...> args;
    ResultType expected;

    template<typename T>
    void print_argument(const T& arg);

    template<size_t Index = 0>
    void print_arguments();

    void print_expected();

    void print_result(ResultType result);

public:
    TestCase(Args... args, ResultType expected);

    template<size_t... IdxSeq>
    ResultType call_function(std::index_sequence<IdxSeq...>, ResultType (*func)(Args...));

    bool run(ResultType (*func)(Args...), bool verbose = true);
};

#include "TestCase.tpp"
