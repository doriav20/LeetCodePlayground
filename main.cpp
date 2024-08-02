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

#include "TestsTool.h"
#include "utils.h"

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
