#include <stdio.h>

using namespace std;

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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode virtual_node;
        ListNode * tmp_head = &virtual_node;
        while (head != nullptr && head->next != nullptr)
        {
            ListNode *node1 = head, *node2 = head->next;
            head = head->next->next;
            node2->next = node1, node1->next = nullptr;
            tmp_head->next = node2;
            tmp_head = node1;
        }
        if (head != nullptr)
        {
            tmp_head->next = head;
        }
        return virtual_node.next;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
