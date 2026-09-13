#include <cstddef>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "TestCase/TestCase.hpp"
#include "colored/colored.hpp"
#include "concepts/concepts.hpp"


namespace _internal
{
inline void print_summary(const std::vector<bool>& results)
{
    size_t passed_count = 0;
    for (size_t i = 0; i < results.size(); i++)
    {
        if (results[i])
        {
            std::cout << colored::green << "Test " << i + 1 << " passed" << colored::reset << std::endl;
            passed_count++;
        }
        else
        {
            std::cout << colored::red << "Test " << i + 1 << " failed" << colored::reset << std::endl;
        }
    }
    if (passed_count == results.size())
    {
        std::cout << colored::green << colored::bold << "All tests passed" << colored::reset << std::endl;
    }
    else
    {
        std::cout << colored::red << colored::bold << passed_count << "/" << results.size() << " tests passed"
                << colored::reset << std::endl;
    }
}

template<typename Class, typename ResultType, typename... Args>
std::function<ResultType(Args...)> make_method_caller(ResultType (Class::*method)(Args...))
{
    return [method](Args... args) -> ResultType
    {
        Class solution;
        return (solution.*method)(std::forward<Args>(args)...);
    };
}
}


template<typename ResultType, typename... Args>
TestsTool<ResultType, Args...>::TestsTool(ResultType (*func)(Args...)) : m_func(func) {}

template<typename ResultType, typename... Args>
template<typename Class>
TestsTool<ResultType, Args...>::TestsTool(ResultType (Class::*method)(Args...)) :
        m_func(_internal::make_method_caller(method)) {}

template<typename ResultType, typename... Args>
void TestsTool<ResultType, Args...>::add_test_case(const TestCase<ResultType, Args...>& test_case)
{
    m_test_cases.push_back(test_case);
}

template<typename ResultType, typename... Args>
void TestsTool<ResultType, Args...>::add_test_case(bare_t<Args>... args, bare_t<ResultType> expected)
{
    m_test_cases.emplace_back(std::move(args)..., std::move(expected));
}

template<typename ResultType, typename... Args>
void TestsTool<ResultType, Args...>::run_tests(const bool verbose)
{
    if (!m_func)
    {
        throw std::runtime_error("No function is set");
    }

    std::vector<bool> results;
    for (TestCase<ResultType, Args...>& test_case : m_test_cases)
    {
        results.push_back(test_case.run(m_func, verbose));
    }

    _internal::print_summary(results);
}


template<typename... Args>
TestsTool<void, Args...>::TestsTool(void (*func)(Args...)) : m_func(func) {}

template<typename... Args>
template<typename Class>
TestsTool<void, Args...>::TestsTool(void (Class::*method)(Args...)) : m_func(_internal::make_method_caller(method)) {}

template<typename... Args>
void TestsTool<void, Args...>::add_test_case(const TestCase<void, Args...>& test_case)
{
    m_test_cases.push_back(test_case);
}

template<typename... Args>
void TestsTool<void, Args...>::add_test_case(bare_t<Args>... args)
{
    m_test_cases.emplace_back(std::move(args)...);
}

template<typename... Args>
void TestsTool<void, Args...>::run_tests(const bool verbose)
{
    if (!m_func)
    {
        throw std::runtime_error("No function is set");
    }

    std::vector<bool> results;
    for (TestCase<void, Args...>& test_case : m_test_cases)
    {
        results.push_back(test_case.run(m_func, verbose));
    }

    _internal::print_summary(results);
}
