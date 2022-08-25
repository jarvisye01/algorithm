#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * key: 更像是数学题目，算法还是要多见识一些东西;
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head && head->next == NULL)
        {
            return NULL;
        }
        ListNode *pSlow = head, *pFast = head;
        while (pFast != NULL && pFast->next != NULL)
        {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if (pFast == pSlow)
            {
                break;
            }
        }
        if (pFast != pSlow)
        {
            return NULL;
        }

        pSlow = head;
        while (pSlow != pFast)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pFast;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
