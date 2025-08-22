#pragma once

#include <vector>

#include "TestCase.hpp"
#include "colored/colored.hpp"

template<typename ResultType, typename... Args>
class TestsTool
{
private:
    std::vector<TestCase<ResultType, Args...>> test_cases;

    using FunctionType = ResultType (*)(Args...);
    FunctionType func;

public:
    explicit TestsTool(FunctionType func);

    void add_test_case(const TestCase<ResultType, Args...>& test_case);

    void add_test_case(Args... args, ResultType expected);

    void run_tests(const bool verbose = true);
};

#include "TestsTool.tpp"
