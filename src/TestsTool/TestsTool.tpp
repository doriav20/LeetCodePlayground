namespace _internal
{
inline void print_summary(const std::vector<bool>& results)
{
    bool all_passed = true;
    for (size_t i = 0; i < results.size(); i++)
    {
        if (results[i])
        {
            std::cout << colored::green << "Test " << i + 1 << " passed" << colored::reset << std::endl;
        }
        else
        {
            std::cout << colored::red << "Test " << i + 1 << " failed" << colored::reset << std::endl;
            all_passed = false;
        }
    }
    if (all_passed)
    {
        std::cout << colored::green << colored::bold << "All tests passed" << colored::reset << std::endl;
    }
}
}


template<typename ResultType, typename... Args>
TestsTool<ResultType, Args...>::TestsTool(TestsTool::FunctionType func) : m_func(func) {}

template<typename ResultType, typename... Args>
void TestsTool<ResultType, Args...>::add_test_case(const TestCase<ResultType, Args...>& test_case)
{
    m_test_cases.push_back(test_case);
}

template<typename ResultType, typename... Args>
void TestsTool<ResultType, Args...>::add_test_case(Args... args, ResultType expected)
{
    m_test_cases.emplace_back(args..., expected);
}

template<typename ResultType, typename... Args>
void TestsTool<ResultType, Args...>::run_tests(const bool verbose)
{
    if (m_func == nullptr)
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
TestsTool<void, Args...>::TestsTool(TestsTool::FunctionType func) : m_func(func) {}

template<typename... Args>
void TestsTool<void, Args...>::add_test_case(const TestCase<void, Args...>& test_case)
{
    m_test_cases.push_back(test_case);
}

template<typename... Args>
void TestsTool<void, Args...>::add_test_case(Args... args)
{
    m_test_cases.emplace_back(args...);
}

template<typename... Args>
void TestsTool<void, Args...>::run_tests(const bool verbose)
{
    if (m_func == nullptr)
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
