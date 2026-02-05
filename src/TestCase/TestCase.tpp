#include "to_string/to_string.hpp"
#include "data_structures/ListNode/ListNode.hpp"
#include "data_structures/TreeNode/TreeNode.hpp"


template<typename ResultType, typename... Args>
template<typename T>
void TestCase<ResultType, Args...>::print_argument(const T& arg)
{
    std::cout << to_string(arg);
}

template<typename ResultType, typename... Args>
template<size_t Index>
void TestCase<ResultType, Args...>::print_arguments()
{
    if constexpr (Index < sizeof...(Args))
    {
        print_argument(std::get<Index>(m_args));
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
    print_argument(m_expected);
}

template<typename ResultType, typename... Args>
void TestCase<ResultType, Args...>::print_result(const ResultType& result)
{
    print_argument(result);
}

template<typename ResultType, typename... Args>
TestCase<ResultType, Args...>::TestCase(const Args... args, const ResultType expected) :
        m_args(std::make_tuple(args...)), m_expected(expected) {}

template<typename ResultType, typename... Args>
template<size_t... IdxSeq>
ResultType TestCase<ResultType, Args...>::call_function(std::index_sequence<IdxSeq...>, ResultType (*func)(Args...))
{
    return func(std::get<IdxSeq>(m_args)...);
}

template<typename ResultType, typename... Args>
bool TestCase<ResultType, Args...>::run(ResultType (* func)(Args...), const bool verbose)
{
    const ResultType actual = call_function(std::index_sequence_for<Args...>{}, func);
    if (!verbose)
    {
        return actual == m_expected;
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
    return actual == m_expected;
}
