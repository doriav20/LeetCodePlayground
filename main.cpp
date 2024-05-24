#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>
#include <stack>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include "utils.h"
#include "TestsTool.h"

using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    return {};
}

int main() {
    cout << boolalpha;

    auto func = twoSum;

    TestsTool tests_tool(func);

    tests_tool.add_test_case({vector<int>{2, 7, 11, 15}, 9, vector<int>{0, 1}});
    tests_tool.add_test_case({vector<int>{3, 2, 4}, 6, vector<int>{1, 2}});
    tests_tool.add_test_case({vector<int>{3, 3}, 6, vector<int>{0, 1}});

    tests_tool.run_tests();

    return 0;
}
