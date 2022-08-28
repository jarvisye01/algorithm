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
        ListNode * pNode = nullptr;
        while (head != nullptr)
        {
            ListNode * pNext = head->next;
            head->next = pNode;
            pNode = head;
            head = pNext;
        }
        return pNode;
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

    ListNode * pHead = Solution().reverseList(&oNode1);
    printf("List: ");
    while (pHead != nullptr)
    {
        printf("%d ", pHead->val);
        pHead = pHead->next;
    }
    printf("\n");
    return 0;
}
