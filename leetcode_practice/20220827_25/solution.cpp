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
private:
    ListNode* reverse(ListNode * head)
    {
        ListNode * pHead = nullptr;
        while (head != nullptr)
        {
            ListNode * pNext = head->next;
            head->next = pHead;
            pHead = head;
            head = pNext;
        }
        return pHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode oVirtualHead, * pHead = &oVirtualHead;
        while (head != nullptr)
        {
            ListNode * pStart = head, *pEnd = nullptr;
            int i = 0;
            for (; i < k && head != nullptr; i++)
            {
                pEnd = head;
                head = head->next;
            }
            pEnd->next = nullptr;
            ListNode * pNextNode = (i == k ? reverse(pStart) : pStart);
            pHead->next = pNextNode;
            pHead = (i == k ? pStart : pEnd);
        }
        return oVirtualHead.next;
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

    ListNode * pHead = Solution().reverseKGroup(&oNode1, 2);
    printf("List: ");
    while (pHead != nullptr)
    {
        printf("%d ", pHead->val);
        pHead = pHead->next;
    }
    printf("\n");
    return 0;
}
