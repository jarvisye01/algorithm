// c library
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// c++ library
#include <cstddef>
#include <vector>

using std::vector;

namespace skiplist
{

constexpr const int kMaxLen = 12;

/*
 * An implementation of SkipList inspired by leveldb.
 * This implamentation can pass all leetcode_1206 test case.
 */
template<typename Key>
class SkipList
{
public:
    struct Node;
    SkipList() noexcept;
    ~SkipList() noexcept;
    SkipList(const SkipList &) = delete;
    SkipList& operator=(const SkipList &) = delete;
    SkipList(const SkipList &&) = delete;
    SkipList& operator=(const SkipList &&) = delete;

    // skiplist methods
    bool Contains(const Key & key);
    void Insert(const Key & key);
    bool Delete(const Key & key);
private:
    Node * FindGreaterOrEqual(const Key & key, vector<Node*> * prevs);
    Node * NewNode(const Key & key, int height);
    int max_height_{1};
    Node * head_;
};

template<typename Key>
struct SkipList<Key>::Node
{
    Key key;
    std::vector<Node*> next_;
};

template<typename Key>
SkipList<Key>::SkipList() noexcept
{
    head_ = new Node;
    head_->key = Key();
    head_->next_.resize(kMaxLen, nullptr);
}

template<typename Key>
SkipList<Key>::~SkipList() noexcept
{
    Node * node = head_;
    while (node != nullptr)
    {
        Node * tmp = node;
        node = node->next_[0];
        delete tmp, tmp = nullptr;
    }
}

template<typename Key>
typename SkipList<Key>::Node*
SkipList<Key>::FindGreaterOrEqual(const Key & key, vector<Node*> * prevs)
{
    int level = max_height_ - 1;
    Node * x = head_;
    while (true)
    {
        Node * next = x->next_[level];
        if (next != nullptr && next->key < key)
        {
            x = next;
        }
        else
        {
            if (prevs != nullptr)
                (*prevs)[level] = x;

            if (level == 0)
                return next;

            level--;
        }
    }
    return nullptr;
}

template<typename Key>
typename SkipList<Key>::Node*
SkipList<Key>::NewNode(const Key & key, int height)
{
    Node * node = new Node;
    node->key = key;
    node->next_.resize(height, nullptr);
    return node;
}

template<typename Key>
bool SkipList<Key>::Contains(const Key & key)
{
    Node * x = FindGreaterOrEqual(key, nullptr);
    if (x != nullptr && x->key == key)
    {
        return true;
    }
    return false;
}

template<typename Key>
void SkipList<Key>::Insert(const Key & key)
{
    std::vector<Node*> prevs(kMaxLen, nullptr);
    Node * tmp = FindGreaterOrEqual(key, &prevs);

    int height = 1;
    while (height < kMaxLen && (rand() % 4) == 0)
    {
        height++;
    }

    Node * new_node = NewNode(key, height);

    if (height > max_height_)
    {
        for (int i = max_height_; i < height; i++)
        {
            prevs[i] = head_;
        }
        max_height_ = height;
    }

    for (int i = 0; i < height; i++)
    {
        new_node->next_[i] = prevs[i]->next_[i];
        prevs[i]->next_[i] = new_node;
    }

    return;
}

template<typename Key>
bool SkipList<Key>::Delete(const Key & key)
{
    std::vector<Node*> prevs(kMaxLen, nullptr);
    Node * tmp = FindGreaterOrEqual(key, &prevs);
    if (tmp == nullptr || tmp->key != key)
        return false;

    for (int i = 0; i < tmp->next_.size(); i++)
    {
        prevs[i]->next_[i] = tmp->next_[i];
    }
    delete tmp, tmp = nullptr;
    return true;
}

};

int main(int argc, char ** argv)
{
    using skiplist::SkipList;

    SkipList<int> slist;

    for (int i = 0; i < 100; i++)
    {
        slist.Insert(i);
    }

    for (int i = 0; i < 1000; i++)
    {
        printf("Contains(%d): %d\n", i, slist.Contains(i) ? 1 : 0);
    }

    return 0;
}
