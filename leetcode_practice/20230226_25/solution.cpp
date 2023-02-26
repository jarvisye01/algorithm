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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode v_node, *v_head = &v_node;
        while (head != nullptr)
        {
            ListNode* start = head, *end = nullptr;;
            int i = 0;
            for (; i < k && head != nullptr; i++)
            {
                end = head;
                head = head->next;
            }
            end->next = nullptr;
            ListNode* next_node = (i == k) ? reverse(start) : start;
            v_head->next = next_node;
            v_head = (i == k) ? start : end;
        }
        return v_node.next;
    }
private:
    ListNode* reverse(ListNode* node)
    {
        ListNode* head = nullptr;
        while (node != nullptr)
        {
            ListNode * tmp = node;
            node = node->next;
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};

int main(int argc, char ** argv)
{
    ListNode oNode1(1);
    ListNode oNode2(2);
    ListNode oNode3(3);
    ListNode oNode4(4);
    ListNode oNode5(5);

    oNode1.next = &oNode2;
    oNode2.next = &oNode3;
    oNode3.next = &oNode4;
    oNode4.next = &oNode5;

    ListNode * head = Solution().reverseKGroup(&oNode1, 2);
    printf("List: ");
    while (head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
