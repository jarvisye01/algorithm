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
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode v_node, *v_head = &v_node;
        int tmp = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int a = l1 != nullptr ? l1->val : 0;
            int b = l2 != nullptr ? l2->val : 0;
            v_head->next = new ListNode((a + b + tmp) % 10);
            tmp = (a + b + tmp) / 10;
            v_head = v_head->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (tmp > 0)
            v_head->next = new ListNode(tmp);
        return v_node.next;
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

    node3.next = &node4;
    node4.next = &node5;

    ListNode *head = Solution().addTwoNumbers(&node1, &node3);
    printf("List: ");
    while (head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
