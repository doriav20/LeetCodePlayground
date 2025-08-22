#pragma once

#include <vector>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* create_list_node_from_vector(const std::vector<int>& vec);
