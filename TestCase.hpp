#pragma once

#include <ostream>
#include <tuple>

#include "utils.hpp"

template<typename ResultType, typename... Args>
class TestCase {
private:
    std::tuple<Args...> args;
    ResultType expected;

    template<typename T>
    void print_argument(const std::vector<T>& arg) {
        std::cout << vector_to_string(arg);
    }

    template<typename T>
    void print_argument(const std::vector<std::vector<T>>& arg) {
        std::cout << matrix_to_string(arg);
    }

    template<typename T>
    void print_argument(const std::stack<T>& arg) {
        std::cout << stack_to_string(arg);
    }

    void print_argument(const ListNode* arg) {
        std::cout << list_node_to_string(arg);
    }


    void print_argument(const TreeNode* arg) {
        std::cout << tree_node_to_string(arg);
    }

    template<typename T>
    void print_argument(const T& arg) {
        std::cout << arg;
    }

    template<size_t Index = 0>
    void print_arguments() {
        if constexpr (Index < sizeof...(Args)) {
            print_argument(std::get<Index>(args));
            if constexpr (Index + 1 < sizeof...(Args)) {
                std::cout << ", ";
            }
            print_arguments<Index + 1>();
        }
    }

    void print_expected() {
        print_argument(expected);
    }

    void print_result(ResultType result) {
        print_argument(result);
    }

public:
    TestCase(Args... args, ResultType expected) : args(std::make_tuple(args...)), expected(expected) {}

    template<size_t... IdxSeq>
    auto call_function(std::index_sequence<IdxSeq...>, ResultType (*func)(Args...)) {
        return func(std::get<IdxSeq>(args)...);
    }

    bool run(ResultType (*func)(Args...), bool verbose = true) {
        auto actual = call_function(std::index_sequence_for<Args...>{}, func);
        if (!verbose) {
            return actual == expected;
        }
        if constexpr (sizeof...(Args) > 0) {
            std::cout << "Arguments: ";
            print_arguments();
            std::cout << std::endl;
        }

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
