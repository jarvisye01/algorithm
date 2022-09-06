#include <stdio.h>

using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode virtual_head;
        ListNode * head = &virtual_head;
        int tmp = 0;

        while (l1 !=  nullptr || l2 != nullptr)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;

            head->next = new ListNode((a + b + tmp) % 10);
            tmp = (a + b + tmp) / 10;
            head = head->next;
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }

        if (tmp > 0)
        {
            head->next = new ListNode(tmp);
        }

        return virtual_head.next;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
