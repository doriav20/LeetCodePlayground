#include <functional>
#include <iostream>
#include <tuple>
#include <utility>

#include "concepts/concepts.hpp"
#include "equals/equals.hpp"
#include "to_string/to_string.hpp"


namespace detail
{
template<typename... Ts>
void print_arguments(const std::tuple<Ts...>& args)
{
    if constexpr (sizeof...(Ts) > 0)
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
}


template<typename ResultType, typename... Args>
TestCase<ResultType, Args...>::TestCase(bare_t<Args>... args, bare_t<ResultType> expected) :
        m_args(std::move(args)...), m_expected(std::move(expected)) {}

template<typename ResultType, typename... Args>
bool TestCase<ResultType, Args...>::run(const std::function<ResultType(Args...)>& func, const bool verbose)
{
    if (verbose)
    {
        detail::print_arguments(m_args);
    }

    std::tuple<bare_t<Args>...> args = m_args;
    const bare_t<ResultType> actual = std::apply(func, args);
    const bool passed = are_equal(actual, m_expected);
    if (!verbose)
    {
        return passed;
    }

    std::cout << "Expected: " << to_string(m_expected) << std::endl;
    std::cout << "Actual: " << to_string(actual) << std::endl;

    std::cout << std::endl;
    return passed;
}


template<typename... Args>
TestCase<void, Args...>::TestCase(bare_t<Args>... args) : m_args(std::move(args)...) {}

template<typename... Args>
bool TestCase<void, Args...>::run(const std::function<void(Args...)>& func, const bool verbose)
{
    if (verbose)
    {
        detail::print_arguments(m_args);
    }

    std::tuple<bare_t<Args>...> args = m_args;
    std::apply(func, args);
    if (!verbose)
    {
        return true;
    }

    std::cout << "Expected: **void**" << std::endl <<
            "Actual: **void**" << std::endl;

    std::cout << std::endl;
    return true;
}
