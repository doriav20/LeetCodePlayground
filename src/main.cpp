#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "TestsTool/TestsTool.hpp"

using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    cout << boolalpha;

    const auto func = sum;

    TestsTool tests_tool(func);

    tests_tool.add_test_case(2, 3, 5);
    tests_tool.add_test_case(-1, 1, 0);
    tests_tool.add_test_case(4, 6, 10);

    tests_tool.run_tests();

    return 0;
}
