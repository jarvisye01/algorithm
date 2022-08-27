#include <stdio.h>

using namespace std;

struct ListNode {
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
        ListNode oVirtualHead;
        ListNode * pHead = &oVirtualHead;
        while (head != nullptr)
        {
            int iNum = head->val;
            ListNode * pos = head;
            while (head->next != nullptr && head->next->val == iNum)
            {
                head = head->next;
            }
            if (pos == head)
            {
                pHead->next = head;
                pHead = head;
            }
            head = head->next;
            pHead->next = nullptr;
        }
        return oVirtualHead.next;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
