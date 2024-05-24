#ifndef LEETCODEPLAYGROUND_TESTCASE_H
#define LEETCODEPLAYGROUND_TESTCASE_H


#include <ostream>
#include "utils.h"

template<typename ResultType, typename Arg1Type, typename Arg2Type=bool, typename Arg3Type=bool>
class TestCase {
private:
    Arg1Type arg1;
    Arg2Type arg2;
    Arg3Type arg3;

    ResultType expected;

    template<typename T>
    void print_argument(const T& arg) {
        if constexpr (std::is_same<T, std::vector<int>>::value ||
                      std::is_same<T, std::vector<int>&>::value ||
                      std::is_same<T, std::vector<std::string>>::value ||
                      std::is_same<T, std::vector<std::string>&>::value ||
                      std::is_same<T, std::vector<char>>::value ||
                      std::is_same<T, std::vector<char>&>::value ||
                      std::is_same<T, std::vector<std::vector<int>>>::value ||
                      std::is_same<T, std::vector<std::vector<int>>&>::value ||
                      std::is_same<T, std::vector<std::vector<std::string>>>::value ||
                      std::is_same<T, std::vector<std::vector<std::string>>&>::value ||
                      std::is_same<T, std::vector<std::vector<char>>>::value ||
                      std::is_same<T, std::vector<std::vector<char>>&>::value) {
            std::cout << vector_to_string(static_cast<const T&>(arg));
        }
        else if constexpr (std::is_same<T, ListNode*>::value) {
            std::cout << list_node_to_string(static_cast<ListNode*>(arg));
        }
        else if constexpr (std::is_same<T, TreeNode*>::value) {
            std::cout << tree_node_to_string(static_cast<TreeNode*>(arg));
        }
        else {
            std::cout << arg;
        }
    }

    void print_arg1() {
        print_argument(arg1);
    }

    void print_arg2() {
        print_argument(arg2);
    }

    void print_arg3() {
        print_argument(arg3);
    }

    void print_expected() {
        print_argument(expected);
    }

    void print_result(ResultType result) {
        print_argument(result);
    }

public:
    TestCase(Arg1Type arg1, ResultType expected) : arg1(arg1), expected(expected), arg2(), arg3() {
    }

    TestCase(Arg1Type arg1, Arg2Type arg2, ResultType expected) : arg1(arg1), arg2(arg2), expected(expected),
                                                                  arg3() {
    }

    TestCase(Arg1Type arg1, Arg2Type arg2, Arg3Type arg3, ResultType expected) : arg1(arg1), arg2(arg2),
                                                                                 arg3(arg3),
                                                                                 expected(expected) {
    }

    bool run(ResultType (* func)(Arg1Type), bool verbose = true) {
        auto actual = func(arg1);
        if (!verbose) {
            return actual == expected;
        }
        std::cout << "Arguments: ";
        print_arg1();
        std::cout << std::endl;

        std::cout << "Expected: ";
        print_expected();
        std::cout << std::endl;

        std::cout << "Actual: ";
        print_result(actual);
        std::cout << std::endl;

        std::cout << std::endl;
        return actual == expected;
    }

    bool run(ResultType (* func)(Arg1Type, Arg2Type), bool verbose = true) {
        auto actual = func(arg1, arg2);
        if (!verbose) {
            return actual == expected;
        }
        std::cout << "Arguments: ";
        print_arg1();
        std::cout << ", ";
        print_arg2();
        std::cout << std::endl;

        std::cout << "Expected: ";
        print_expected();
        std::cout << std::endl;

        std::cout << "Actual: ";
        print_result(actual);
        std::cout << std::endl;

        std::cout << std::endl;
        return actual == expected;
    }

    bool run(ResultType (* func)(Arg1Type, Arg2Type, Arg3Type), bool verbose = true) {
        auto actual = func(arg1, arg2, arg3);
        if (!verbose) {
            return actual == expected;
        }
        std::cout << "Arguments: ";
        print_arg1();
        std::cout << ", ";
        print_arg2();
        std::cout << ", ";
        print_arg3();
        std::cout << std::endl;

        std::cout << "Expected: ";
        print_expected();
        std::cout << std::endl;

        std::cout << "Actual: ";
        print_result(actual);
        std::cout << std::endl;

        std::cout << std::endl;
        return actual == expected;
    }
};


#endif //LEETCODEPLAYGROUND_TESTCASE_H
