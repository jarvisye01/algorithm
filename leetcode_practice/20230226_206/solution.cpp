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
    ListNode* reverseList(ListNode* head)
    {
        ListNode *tmp_head = nullptr;
        while (head != nullptr)
        {
            ListNode * tmp = head;
            head = head->next;
            tmp->next = tmp_head;
            tmp_head = tmp;
        }
        return tmp_head;
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

    ListNode * head = Solution().reverseList(&oNode1);

    printf("List: ");
    while (head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    return 0;
}
