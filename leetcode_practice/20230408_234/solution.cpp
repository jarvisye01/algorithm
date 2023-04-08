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
    bool isPalindrome(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *l1 = head;
        ListNode *l2 = Reverse(GetMid(head));
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val != l2->val)
                return false;
            l1 = l1->next, l2 = l2->next;
        }
        return true;
    }
private:
    ListNode* GetMid(ListNode * head)
    {
        ListNode *slow = head, *fast = head, *last_slow = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            last_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (last_slow != nullptr)
            last_slow->next = nullptr;
        return slow;
    }
    ListNode * Reverse(ListNode * head)
    {
        ListNode * t_head = nullptr;
        while (head != nullptr)
        {
            ListNode * tmp = head;
            head = head->next;
            tmp->next = t_head;
            t_head = tmp;
        }
        return t_head;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
