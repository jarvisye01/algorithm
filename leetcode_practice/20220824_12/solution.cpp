#include <stdio.h>
#include <set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * key: 两种思路，快慢指针和set;
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        set<ListNode*> oNodeSet;
        while (head != NULL)
        {
            if (oNodeSet.find(head) != oNodeSet.end())
            {
                return true;
            }
            oNodeSet.insert(head);
            head = head->next;
        }
        return false;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
