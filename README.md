# LeetCodePlayground

A small C++ playground for solving LeetCode problems locally: paste a solution, add test cases, and run them.

## Requirements

- CMake 3.26+
- A compiler with C++26 support (tested with GCC 15, GCC 16 and Clang 21)

Or just Docker, see [Docker](#docker).

## Getting Started

```bash
cmake -S . -B build
cmake --build build
./build/LeetCodePlayground
```

Write your solution and its test cases in `src/main.cpp`.

### Options

| Option               | Default | Description                         |
|----------------------|---------|-------------------------------------|
| `WARNINGS_AS_ERRORS` | `OFF`   | Treat compiler warnings as errors   |

```bash
cmake -S . -B build -DWARNINGS_AS_ERRORS=ON
```

### Docker

Build the image and run the playground:

```bash
docker build -t leetcode-playground .
docker run --rm leetcode-playground
```

To run your local sources without rebuilding the image, mount the project directory:

```bash
docker run --rm -v "$(pwd):/LeetCodePlayground" leetcode-playground
```

Pass `--build-arg WARNINGS_AS_ERRORS=ON` to `docker build` to treat warnings as errors.

## Writing Tests

Paste the `Solution` class as is and pass the method to `TestsTool`.
Each test case is the function arguments followed by the expected result:

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) { ... }
};

int main()
{
    TestsTool tests_tool(&Solution::twoSum);

    tests_tool.add_test_case({2, 7, 11, 15}, 9, {0, 1});
    tests_tool.add_test_case({3, 2, 4}, 6, {1, 2});

    tests_tool.run_tests();
}
```

- A new `Solution` instance is created for each test case.
- Arguments are printed before the call, so solutions that modify their input in place still show the original input.
- Free functions work the same way: `TestsTool tests_tool(two_sum);`
- For `void` functions, pass only the arguments: `tests_tool.add_test_case({1, 2, 3}, 2);`
- Call `run_tests(false)` to print only the summary.

Output:

```
Arguments: [ 2, 7, 11, 15 ], 9
Expected: [ 0, 1 ]
Actual: [ 0, 1 ]

Test 1 passed
Test 2 passed
All tests passed
```

## Data Structures

`ListNode` and `TreeNode` match LeetCode's definitions, and results are compared by value.

```cpp
ListNode* head = create_list_node_from_vector({1, 2, 3});             // 1 --> 2 --> 3
TreeNode* root = create_tree_node_from_vector({1, NULL_NODE, 2, 3});  // [ 1, null, 2, 3 ]
```

Trees use LeetCode's level order format, with `NULL_NODE` in place of `null`.
