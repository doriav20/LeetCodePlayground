template<typename ResultType, typename... Args>
TestsTool<ResultType, Args...>::TestsTool(TestsTool::FunctionType func) : func(func) {}

template<typename ResultType, typename... Args>
void TestsTool<ResultType, Args...>::add_test_case(const TestCase<ResultType, Args...>& test_case)
{
    test_cases.push_back(test_case);
}

template<typename ResultType, typename... Args>
void TestsTool<ResultType, Args...>::add_test_case(Args... args, ResultType expected)
{
    test_cases.emplace_back(args..., expected);
}

template<typename ResultType, typename... Args>
void TestsTool<ResultType, Args...>::run_tests(const bool verbose)
{
    if (func == nullptr)
    {
        throw std::runtime_error("No function is set");
    }

    std::vector<bool> results(test_cases.size());
    size_t i = 0;

    for (TestCase<ResultType, Args...>& test_case : test_cases)
    {
        const bool passed = test_case.run(func, verbose);
        results[i++] = passed;
    }

    bool all_passed = true;
    for (i = 0; i < results.size(); i++)
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
