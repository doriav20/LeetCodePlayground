#include "to_string/to_string.hpp"
#include "data_structures/ListNode/ListNode.hpp"
#include "data_structures/TreeNode/TreeNode.hpp"


namespace _internal
{
template<typename... Ts>
void print_arguments(const std::tuple<Ts...>& args)
{
    std::cout << "Arguments: ";
    std::apply([](const auto& first, const auto&... rest)
    {
        std::cout << to_string(first);
        ((std::cout << ", " << to_string(rest)), ...);
    }, args);
    std::cout << std::endl;
}
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
        _internal::print_arguments(m_args);
    }

    std::cout << "Expected: " << to_string(m_expected) << std::endl;
    std::cout << "Actual: " << to_string(actual) << std::endl;

    std::cout << std::endl;
    return actual == m_expected;
}


template<typename... Args>
TestCase<void, Args...>::TestCase(const Args... args) : m_args(std::make_tuple(args...)) {}

template<typename... Args>
template<size_t... IdxSeq>
void TestCase<void, Args...>::call_function(std::index_sequence<IdxSeq...>, void (*func)(Args...))
{
    func(std::get<IdxSeq>(m_args)...);
}

template<typename... Args>
bool TestCase<void, Args...>::run(void (* func)(Args...), const bool verbose)
{
    call_function(std::index_sequence_for<Args...>{}, func);
    if (!verbose)
    {
        return true;
    }
    if constexpr (sizeof...(Args) > 0)
    {
        _internal::print_arguments(m_args);
    }

    std::cout << "Expected: **void**" << std::endl <<
            "Actual: **void**" << std::endl;

    std::cout << std::endl;
    return true;
}
