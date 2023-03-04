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
    ListNode* getIntersectionNode(ListNode * headA, ListNode * headB)
    {
        ListNode *node1 = headA, *node2 = headB;
        while (node1 != nullptr || node2 != nullptr)
        {
            if (node1 == node2)
                return node1;
            node1 = node1 != nullptr ? node1->next : headB;
            node2 = node2 != nullptr ? node2->next : headA;
        }
        return nullptr;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
