#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using std::vector;

namespace skiplist
{

const int MAX_LEN = 20;

struct SkipNode;

struct ListNode
{
    ListNode * pNext;
    SkipNode * pNode;
    ListNode(): pNext(nullptr), pNode(nullptr)
    {
    }
    ~ListNode()
    {
    }
};

struct SkipNode
{
    int iKey;
    vector<ListNode*> oLevelNode;
    SkipNode * pNext;
    SkipNode(): iKey(-1), pNext(nullptr)
    {
    }
    ~SkipNode()
    {
        for (size_t i = 0; i < oLevelNode.size(); i++)
        {
            delete oLevelNode[i], oLevelNode[i] = nullptr;
        }
    }
};

class SkipList
{
public:
    SkipList();
    ~SkipList();
    bool IsKeyExist(int iKey);
    void InsertKey(int iKey);
    void DeleteKey(int iKey);
    void Print();
private:
    SkipNode* SearchNode(int iKey, vector<ListNode*> & oPreNodes, bool bNoBigger);
private:
    SkipNode oSentinel;
};

SkipList::SkipList()
{
    srand(time(nullptr));
    oSentinel.oLevelNode.resize(MAX_LEN, nullptr);
    for (size_t i = 0; i < oSentinel.oLevelNode.size(); i++)
    {
        oSentinel.oLevelNode[i] = new ListNode;
        oSentinel.oLevelNode[i]->pNext = nullptr;
        oSentinel.oLevelNode[i]->pNode = &oSentinel;
    }
}

SkipList::~SkipList()
{
}

bool SkipList::IsKeyExist(int iKey)
{
    vector<ListNode*> oPreNodes;
    SkipNode * pSkipNode = SearchNode(iKey, oPreNodes, true);
    if (pSkipNode != nullptr && pSkipNode->iKey == iKey)
    {
        return true;
    }
    return false;
}

void SkipList::InsertKey(int iKey)
{
    vector<ListNode*> oPreNodes;
    SkipNode * pSkipNode = SearchNode(iKey, oPreNodes, true);
    if (pSkipNode != nullptr && pSkipNode->iKey == iKey)
    {
        return;
    }
    pSkipNode = new SkipNode;
    pSkipNode->iKey = iKey;
    pSkipNode->oLevelNode.resize(rand() % MAX_LEN + 1);
    printf("size: %d\n", pSkipNode->oLevelNode.size());
    for (int i = pSkipNode->oLevelNode.size() - 1; i >= 0; i--)
    {
        pSkipNode->oLevelNode[i] = new ListNode;
        pSkipNode->oLevelNode[i]->pNode = pSkipNode;
        pSkipNode->oLevelNode[i]->pNext = oPreNodes[i]->pNext;
        oPreNodes[i]->pNext = pSkipNode->oLevelNode[i];
    }
    pSkipNode->pNext = oPreNodes[0]->pNode->pNext;
    oPreNodes[0]->pNode->pNext = pSkipNode;
    return;
}

void SkipList::DeleteKey(int iKey)
{
    vector<ListNode*> oPreNodes;
    SkipNode * pSkipNode = SearchNode(iKey, oPreNodes, false);
    if (pSkipNode == nullptr || pSkipNode->pNext == nullptr ||  pSkipNode->pNext->iKey != iKey)
    {
        return;
    }

    pSkipNode = pSkipNode->pNext;
    for (int i = pSkipNode->oLevelNode.size() - 1; i >= 0; i--)
    {
        oPreNodes[i]->pNext = pSkipNode->oLevelNode[i]->pNext;;
    }
    oPreNodes[0]->pNode->pNext = pSkipNode->pNext;
    delete pSkipNode;
    return;
}

void SkipList::Print()
{
    SkipNode * pHead = &oSentinel;
    printf("SkipList:\n");
    for (size_t i = 0; i < pHead->oLevelNode.size(); i++)
    {
        while (pHead != nullptr)
        {
            if (i < pHead->oLevelNode.size())
            {
                printf("%d ", pHead->iKey);
            }
            else
            {
                printf("  ");
            }
            pHead = pHead->pNext;
        }
        pHead = &oSentinel;
        printf("\n");
    }
    return;
}

SkipNode * SkipList::SearchNode(int iKey, vector<ListNode*> & oPreNodes, bool bNoBigger)
{
    SkipNode * pHead = &oSentinel;
    oPreNodes = oSentinel.oLevelNode;
    for (int i = oSentinel.oLevelNode.size() - 1; i >= 0; i--)
    {
        ListNode * pTmpNode = oSentinel.oLevelNode[i];
        if (pTmpNode == nullptr)
        {
            continue;
        }
        if (pTmpNode->pNext != nullptr &&
                (bNoBigger ? pTmpNode->pNext->pNode->iKey <= iKey : pTmpNode->pNext->pNode->iKey < iKey))
        {
            pHead = pTmpNode->pNext->pNode;
        }
        oPreNodes[i] = pTmpNode;
    }
    if (pHead == nullptr)
    {
        return nullptr;
    }
    for (int k = pHead->oLevelNode.size() - 1; k >= 0; k--)
    {
        oPreNodes[k] = pHead->oLevelNode[k];
    }
    while (pHead != nullptr)
    {
        if (pHead->iKey < iKey)
        {
            int iLevel = pHead->oLevelNode.size() - 1;
            for (; iLevel >= 0; iLevel--)
            {
                if (pHead->oLevelNode[iLevel]->pNext != nullptr &&
                        (bNoBigger ? pHead->oLevelNode[iLevel]->pNext->pNode->iKey <= iKey : pHead->oLevelNode[iLevel]->pNext->pNode->iKey < iKey))
                {
                    pHead = pHead->pNext;
                    break;
                }
            }
            for (int k = pHead->oLevelNode.size() - 1; k >= 0; k--)
            {
                oPreNodes[k] = pHead->oLevelNode[k];
            }
            if (iLevel < 0)
            {
                break;
            }
        }
        else
        {
            return pHead;
        }
    }
    return pHead;
}

}   // namespace skiplist

int main(int argc, char ** argv)
{
    skiplist::SkipList oList;
    printf("SkipList Insert(1, 3, 2, 4, 0, 5, 9, 8):\n");
    oList.InsertKey(1);
    oList.InsertKey(3);
    oList.InsertKey(2);
    oList.InsertKey(4);
    oList.InsertKey(0);
    oList.InsertKey(9);
    oList.InsertKey(8);
    oList.Print();
    printf("\n");

    printf("SkipList Delete(4):\n");
    oList.DeleteKey(4);
    oList.Print();
    printf("IsKeyExist(%d): %d\n", 0, oList.IsKeyExist(0) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 1, oList.IsKeyExist(1) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 2, oList.IsKeyExist(2) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 3, oList.IsKeyExist(3) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 4, oList.IsKeyExist(4) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 5, oList.IsKeyExist(5) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 8, oList.IsKeyExist(8) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 9, oList.IsKeyExist(9) ? 1 : 0);
    printf("\n");

    printf("SkipList Delete(5):\n");
    oList.DeleteKey(5);
    oList.Print();
    printf("IsKeyExist(%d): %d\n", 0, oList.IsKeyExist(0) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 1, oList.IsKeyExist(1) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 2, oList.IsKeyExist(2) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 3, oList.IsKeyExist(3) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 4, oList.IsKeyExist(4) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 5, oList.IsKeyExist(5) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 8, oList.IsKeyExist(8) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 9, oList.IsKeyExist(9) ? 1 : 0);
    printf("\n");

    printf("SkipList Delete(9):\n");
    oList.DeleteKey(9);
    oList.Print();
    printf("IsKeyExist(%d): %d\n", 0, oList.IsKeyExist(0) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 1, oList.IsKeyExist(1) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 2, oList.IsKeyExist(2) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 3, oList.IsKeyExist(3) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 4, oList.IsKeyExist(4) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 5, oList.IsKeyExist(5) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 8, oList.IsKeyExist(8) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 9, oList.IsKeyExist(9) ? 1 : 0);
    printf("\n");

    printf("SkipList Delete(0):\n");
    oList.DeleteKey(0);
    oList.Print();
    printf("IsKeyExist(%d): %d\n", 0, oList.IsKeyExist(0) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 1, oList.IsKeyExist(1) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 2, oList.IsKeyExist(2) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 3, oList.IsKeyExist(3) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 4, oList.IsKeyExist(4) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 5, oList.IsKeyExist(5) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 8, oList.IsKeyExist(8) ? 1 : 0);
    printf("IsKeyExist(%d): %d\n", 9, oList.IsKeyExist(9) ? 1 : 0);
    printf("\n");
    return 0;
}
