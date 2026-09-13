#pragma once

#include <functional>
#include <vector>

#include "TestCase/TestCase.hpp"
#include "concepts/concepts.hpp"

template<typename ResultType, typename... Args>
class TestsTool
{
private:
    std::vector<TestCase<ResultType, Args...>> m_test_cases;

    std::function<ResultType(Args...)> m_func;

public:
    explicit TestsTool(ResultType (*func)(Args...));

    template<typename Class>
    explicit TestsTool(ResultType (Class::*method)(Args...));

    void add_test_case(const TestCase<ResultType, Args...>& test_case);

    void add_test_case(bare_t<Args>... args, bare_t<ResultType> expected);

    void run_tests(const bool verbose = true);
};

template<typename... Args>
class TestsTool<void, Args...>
{
private:
    std::vector<TestCase<void, Args...>> m_test_cases;

    std::function<void(Args...)> m_func;

public:
    explicit TestsTool(void (*func)(Args...));

    template<typename Class>
    explicit TestsTool(void (Class::*method)(Args...));

    void add_test_case(const TestCase<void, Args...>& test_case);

    void add_test_case(bare_t<Args>... args);

    void run_tests(const bool verbose = true);
};

#include "TestsTool.tpp"
