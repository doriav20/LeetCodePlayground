#pragma once

#include <vector>

#include "TestCase/TestCase.hpp"
#include "colored/colored.hpp"

template<typename ResultType, typename... Args>
class TestsTool
{
private:
    std::vector<TestCase<ResultType, Args...>> m_test_cases;

    using FunctionType = ResultType (*)(Args...);
    FunctionType m_func;

public:
    explicit TestsTool(FunctionType func);

    void add_test_case(const TestCase<ResultType, Args...>& test_case);

    void add_test_case(Args... args, ResultType expected);

    void run_tests(const bool verbose = true);
};

template<typename... Args>
class TestsTool<void, Args...>
{
private:
    std::vector<TestCase<void, Args...>> m_test_cases;

    using FunctionType = void (*)(Args...);
    FunctionType m_func;

public:
    explicit TestsTool(FunctionType func);

    void add_test_case(const TestCase<void, Args...>& test_case);

    void add_test_case(Args... args);

    void run_tests(const bool verbose = true);
};

#include "TestsTool.tpp"
