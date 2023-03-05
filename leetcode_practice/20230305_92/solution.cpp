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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (left >= right)
            return head;

        ListNode v_node, *v_head = &v_node;
        v_head->next = head;
        int idx = 0;
        while (idx + 1 < left)
        {
            v_head = v_head->next;
            ++idx;
        }
        ListNode *start = v_head->next, *last = v_head;
        while (idx < right)
        {
            v_head = v_head->next;
            ++idx;
        }
        ListNode *end = v_head;
        v_head = v_head->next, end->next = nullptr;
        last->next = reverse(start);
        start->next = v_head;
        return v_node.next;
    }
private:
    ListNode* reverse(ListNode * head)
    {
        ListNode *v_head = nullptr;
        while (head != nullptr)
        {
            ListNode * tmp = head;
            head = head->next;
            tmp->next = v_head;
            v_head = tmp;
        }
        return v_head;
    }
};

int main(int argc, char ** argv)
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    ListNode *head = Solution().reverseBetween(&node1, 2, 4);
    printf("List: ");
    while (head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
