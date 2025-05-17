#include "utils.hpp"

template<typename T>
concept IsVector =
requires(T t) {
    typename T::value_type;
    requires std::same_as<T, std::vector<typename T::value_type>>;
};

template<typename T>
concept IsMatrix =
requires(T t) {
    typename T::value_type;
    requires std::same_as<typename T::value_type, std::vector<typename T::value_type::value_type>>;
};

template<typename T>
concept IsStack =
requires(T t) {
    typename T::value_type;
    requires std::same_as<T, std::stack<typename T::value_type>>;
};

template<typename T>
concept IsListNodePtr = std::same_as<T, const ListNode*>;
template<typename T>
concept IsTreeNodePtr = std::same_as<T, const TreeNode*>;

template<typename ResultType, typename... Args>
template<typename T>
void TestCase<ResultType, Args...>::print_argument(const T& arg)
{
    if constexpr (IsMatrix<T>)
    {
        std::cout << matrix_to_string(arg);
    }
    else if constexpr (IsVector<T>)
    {
        std::cout << vector_to_string(arg);
    }
    else if constexpr (IsStack<T>)
    {
        std::cout << stack_to_string(arg);
    }
    else if constexpr (IsListNodePtr<T>)
    {
        std::cout << list_node_to_string(arg);
    }
    else if constexpr (IsTreeNodePtr<T>)
    {
        std::cout << tree_node_to_string(arg);
    }
    else
    {
        std::cout << arg;
    }
}

template<typename ResultType, typename... Args>
template<size_t Index>
void TestCase<ResultType, Args...>::print_arguments()
{
    if constexpr (Index < sizeof...(Args))
    {
        print_argument(std::get<Index>(args));
        if constexpr (Index + 1 < sizeof...(Args))
        {
            std::cout << ", ";
        }
        print_arguments < Index + 1 > ();
    }
}

template<typename ResultType, typename... Args>
void TestCase<ResultType, Args...>::print_expected()
{
    print_argument(expected);
}

template<typename ResultType, typename... Args>
void TestCase<ResultType, Args...>::print_result(ResultType result)
{
    print_argument(result);
}

template<typename ResultType, typename... Args>
TestCase<ResultType, Args...>::TestCase(Args... args, ResultType expected) :
        args(std::make_tuple(args...)), expected(expected) {}

template<typename ResultType, typename... Args>
template<size_t... IdxSeq>
ResultType TestCase<ResultType, Args...>::call_function(std::index_sequence<IdxSeq...>, ResultType (*func)(Args...))
{
    return func(std::get<IdxSeq>(args)...);
}

template<typename ResultType, typename... Args>
bool TestCase<ResultType, Args...>::run(ResultType (*func)(Args...), bool verbose)
{
    ResultType actual = call_function(std::index_sequence_for<Args...>{}, func);
    if (!verbose)
    {
        return actual == expected;
    }
    if constexpr (sizeof...(Args) > 0)
    {
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
