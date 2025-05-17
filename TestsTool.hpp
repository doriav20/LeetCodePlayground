#pragma once

#include <vector>

#include "TestCase.hpp"
#include "colored/colored.hpp"

template<typename ResultType, typename... Args>
class TestsTool {
private:
    std::vector<TestCase<ResultType, Args...>> test_cases;

    using FunctionType = ResultType (*)(Args...);
    FunctionType func;

public:
    explicit TestsTool(FunctionType func) : func(func) {}

    void add_test_case(const TestCase<ResultType, Args...>& test_case) {
        test_cases.push_back(test_case);
    }

    void add_test_case(Args... args, ResultType expected) {
        test_cases.emplace_back(args..., expected);
    }

    void run_tests(bool verbose = true) {
        std::vector<bool> results(test_cases.size());
        int i = 0;

        if (func != nullptr) {
            for (auto& test_case: test_cases) {
                bool passed = test_case.run(func, verbose);
                results[i++] = passed;
            }
        }
        else {
            throw std::runtime_error("No function is set");
        }

        bool all_passed = true;
        for (i = 0; i < results.size(); i++) {
            if (results[i]) {
                std::cout << colored::green << "Test " << i + 1 << " passed" << std::endl;
            }
            else {
                std::cout << colored::red << "Test " << i + 1 << " failed" << std::endl;
                all_passed = false;
            }
        }
        if (all_passed) {
            std::cout << colored::green << colored::bold << "All tests passed" << std::endl;
        }
    }
};
