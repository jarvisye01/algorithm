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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode v_node, *v_head = &v_node;
        while (head != nullptr)
        {
            ListNode * start = head;
            while (head != nullptr && start->val == head->val)
                head = head->next;
            // 如果head不是start的下一个节点，说明start节点处的值肯定重复了
            if (head == start->next)
            {
                v_head->next = start;
                v_head = v_head->next;
                v_head->next = nullptr;
            }
        }
        return v_node.next;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
