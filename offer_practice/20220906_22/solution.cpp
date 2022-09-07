#include <stdio.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode * getKthFromEnd(ListNode * head, int k)
    {
        ListNode * phead = head;
        int total = 0;
        while (phead != nullptr)
        {
            phead = phead->next;
            total++;
        }

        int tk = total - k;
        if (tk < 0)
        {
            return nullptr;
        }
        for (int i = 0; i < tk; i++)
        {
            head = head->next;
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

    ListNode * head = Solution().getKthFromEnd(&oNode1, 2);
    printf("List: ");
    while ( head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
