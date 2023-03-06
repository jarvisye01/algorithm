#include <cstddef>
#include <cstdio>
#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        int len = 0;
        ListNode* t_head = head;
        while (t_head != nullptr)
        {
            len++;
            t_head = t_head->next;
        }

        t_head = head;
        for (int i = 0; i < (len / 2) - 1; i++)
        {
            t_head = t_head->next;
        }
        ListNode *l1 = head, *l2 = t_head->next;
        t_head->next = nullptr;
        l2 = reverse(l2);
        
        ListNode v_node, *v_head = &v_node;
        bool flag = true;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (flag)
            {
                v_head->next = l1;
                l1 = l1->next;
            }
            else
            {
                v_head->next = l2;
                l2 = l2->next;
            }
            v_head = v_head->next;
            v_head->next = nullptr;
            flag = !flag;
        }
        if (l1 != nullptr)
            v_head->next = l1;
        if (l2 != nullptr)
            v_head->next = l2;
        head = v_node.next;
    }

private:
    ListNode* reverse(ListNode * head)
    {
        ListNode * tmp = nullptr;
        while (head != nullptr)
        {
            ListNode* node = head;
            head = head->next;
            node->next = tmp;
            tmp = node;
        }
        return tmp;
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

    ListNode * head = &node1;
    Solution().reorderList(head);
    printf("List: ");
    while (head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
