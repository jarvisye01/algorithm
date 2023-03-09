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
    ListNode* sortList(ListNode * head)
    {
        auto mid_node = GetMidNode(head);
        if (head == mid_node)
            return head;
        return MergeTwo(sortList(mid_node), sortList(head));
    }
private:
    ListNode* GetMidNode(ListNode * head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *fast = head, *slow = head, *tail = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            tail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (tail != nullptr)
            tail->next = nullptr;
        return slow;
    }
    ListNode* MergeTwo(ListNode* list1, ListNode* list2)
    {
        ListNode v_node;
        ListNode* head = &v_node;
        while (list1 != nullptr && list2 != nullptr)
        {
            ListNode * next_node = nullptr;
            if (list1->val <= list2->val)
                next_node = list1, list1 = list1->next;
            else
                next_node = list2, list2 = list2->next;
            next_node->next = nullptr;
            head->next = next_node;
            head = next_node;
        }
        if (list1 != nullptr)
            head->next = list1;
        if (list2 != nullptr)
            head->next = list2;
        return v_node.next;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
