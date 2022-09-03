#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode virtual_node;
        ListNode * virtual_head = &virtual_node;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                ListNode * next_node = list1->next;
                virtual_head->next = list1;
                virtual_head = list1;
                virtual_head->next = nullptr;
                list1 = next_node;
            }
            else
            {
                ListNode * next_node = list2->next;
                virtual_head->next = list2;
                virtual_head = list2;
                virtual_head->next = nullptr;
                list2 = next_node;
            }
        }
        if (list1 != nullptr)
        {
            virtual_head->next = list1;
        }
        if (list2 != nullptr)
        {
            virtual_head->next = list2;
        }
        return virtual_node.next;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
