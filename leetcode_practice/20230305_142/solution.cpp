#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution
{
public:
    ListNode * detectCycle(ListNode * head)
    {
        // 排除空节点或者一个节点的非环情况，避免对后续产生干扰
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (fast != slow)
            return nullptr;
        // 只有二者相遇才能去找重合的第一个节点
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
