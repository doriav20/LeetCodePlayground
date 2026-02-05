#pragma once

#include <vector>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : ListNode(0) {}

    ListNode(const int x) : ListNode(x, nullptr) {}

    ListNode(const int x, ListNode* next_ptr) : val(x), next(next_ptr) {}
};

ListNode* create_list_node_from_vector(const std::vector<int>& vec);
