#ifndef LEETCODEPLAYGROUND_TESTSTOOL_H
#define LEETCODEPLAYGROUND_TESTSTOOL_H

#include <vector>
#include <iostream>
#include <windows.h>
#include "TestCase.h"

template<typename ResultType, typename Arg1Type, typename Arg2Type=bool, typename Arg3Type=bool>
class TestsTool {
private:
    std::vector<TestCase<ResultType, Arg1Type, Arg2Type, Arg3Type>> test_cases;

    using FunctionType1 = ResultType (*)(Arg1Type);
    using FunctionType2 = ResultType (*)(Arg1Type, Arg2Type);
    using FunctionType3 = ResultType (*)(Arg1Type, Arg2Type, Arg3Type);

    FunctionType1 func1;
    FunctionType2 func2;
    FunctionType3 func3;


public:
    TestsTool(FunctionType1 func) : func1(func), func2(nullptr), func3(nullptr) {}

    TestsTool(FunctionType2 func) : func1(nullptr), func2(func), func3(nullptr) {}

    TestsTool(FunctionType3 func) : func1(nullptr), func2(nullptr), func3(func) {}


    void add_test_case(const TestCase<ResultType, Arg1Type, Arg2Type, Arg3Type>& test_case) {
        test_cases.push_back(test_case);
    }

    void add_test_case(Arg1Type arg1, Arg2Type arg2, Arg3Type arg3, ResultType resultType) {
        test_cases.push_back(TestCase<ResultType, Arg1Type, Arg2Type, Arg3Type>(arg1, arg2, arg3, resultType));
    }

    void add_test_case(Arg1Type arg1, Arg2Type arg2, ResultType resultType) {
        test_cases.push_back(TestCase<ResultType, Arg1Type, Arg2Type, Arg3Type>(arg1, arg2, resultType));
    }

    void add_test_case(Arg1Type arg1, ResultType resultType) {
        test_cases.push_back(TestCase<ResultType, Arg1Type, Arg2Type, Arg3Type>(arg1, resultType));
    }

    void run_tests(bool verbose = true) {
        std::vector<bool> results(test_cases.size());
        int i = 0;

        if (func1 != nullptr) {
            for (auto& test_case: test_cases) {
                auto passed = test_case.run(func1, verbose);
                results[i++] = passed;
            }
        }
        else if (func2 != nullptr) {
            for (auto& test_case: test_cases) {
                auto passed = test_case.run(func2, verbose);
                results[i++] = passed;
            }
        }
        else if (func3 != nullptr) {
            for (auto& test_case: test_cases) {
                auto passed = test_case.run(func3, verbose);
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


#endif //LEETCODEPLAYGROUND_TESTSTOOL_H
