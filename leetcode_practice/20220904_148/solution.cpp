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
    ListNode* sortList(ListNode* head)
    {
        ListNode * mid_node = GetMid(head);
        if (mid_node == head)
        {
            return head;
        }

        ListNode * list1 = head;
        ListNode * list2 = mid_node;
        return Merge(sortList(list1), sortList(list2));
    }
private:
    ListNode * Merge(ListNode * list1, ListNode * list2)
    {
        ListNode virtual_node;
        ListNode * head = &virtual_node;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                head->next = list1;
                list1 = list1->next;
            }
            else
            {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
            head->next = nullptr;
        }
        if (list1)
        {
            head->next = list1;
        }
        if (list2)
        {
            head->next = list2;
        }
        return virtual_node.next;
    }
    ListNode * GetMid(ListNode * head)
    {
        ListNode *slow = head, *fast = head, *last = head;
        while (fast && fast->next)
        {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (last != slow)
        {
            last->next = nullptr;
        }
        return slow;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
