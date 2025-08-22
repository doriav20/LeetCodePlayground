#include "ListNode.hpp"

ListNode* create_list_node_from_vector(const std::vector<int>& vec)
{
    ListNode* head = nullptr;
    ListNode* pos = nullptr;
    for (int num: vec)
    {
        if (head == nullptr)
        {
            head = pos = new ListNode(num);
            continue;
        }
        pos->next = new ListNode(num);
        pos = pos->next;
    }
    return head;
}
