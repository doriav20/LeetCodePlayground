#pragma once

#include <iostream>
#include <vector>
#include <windows.h>

#include "TestCase.hpp"

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
                auto passed = test_case.run(func, verbose);
                results[i++] = passed;
            }
        }
        else {
            throw std::runtime_error("No function is set");
        }

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        bool all_passed = true;
        for (i = 0; i < results.size(); i++) {
            if (results[i]) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                std::cout << "Test " << i + 1 << " passed" << std::endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout << "Test " << i + 1 << " failed" << std::endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                all_passed = false;
            }
        }
        if (all_passed) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "All tests passed" << std::endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }
};
