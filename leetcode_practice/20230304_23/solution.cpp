#include <stdio.h>
#include <vector>

using std::vector;

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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
private:
    ListNode * mergeKLists(vector<ListNode*> & lists, int i, int j)
    {
        if (i > j)
            return nullptr;
        if (i == j)
            return lists[i];
        int mid = i + (j - i) / 2;
        ListNode * l1 = mergeKLists(lists, i , mid);
        ListNode * l2 = mergeKLists(lists, mid + 1 , j);
        return mergeTwo(l1, l2);
    }
    ListNode * mergeTwo(ListNode * l1, ListNode * l2)
    {
        ListNode v_node, *head = &v_node;
        while (l1 != nullptr && l2 != nullptr)
        {
            ListNode * next = nullptr;
            if (l1->val <= l2->val)
            {
                next = l1;
                l1 = l1->next;
            }
            else
            {
                next = l2;
                l2 = l2->next;
            }
            next->next = nullptr;
            head->next = next;
            head = next;
        }
        if (l1 != nullptr)
            head->next = l1;
        if (l2 != nullptr)
            head->next = l2;
        return v_node.next;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
