#include <stdio.h>
#include <map>

using std::map;

struct Node
{
    int key_;
    int val_;
    Node * prev_;
    Node * next_;
    Node(): key_(-1), val_(-1), prev_(nullptr), next_(nullptr) {}
    Node(int k, int v): key_(k), val_(v), prev_(nullptr), next_(nullptr) {}
    Node(int k, int v, Node * p, Node * n): key_(k), val_(v), prev_(p), next_(n) {}
};

struct DeList
{
    DeList(): head_(nullptr), tail_(nullptr) {}
    void push_back(Node * node)
    {
        if (tail_ == nullptr)
        {
            head_ = tail_ = node;
        }
        else
        {
            tail_->next_ = node;
            node->prev_ = tail_;
            tail_ = node;
        }
    }
    void push_front(Node * node)
    {
        if (head_ == nullptr)
        {
            head_ = tail_ = node;
        }
        else
        {
            node->next_ = head_;
            head_->prev_ = node;
            head_ = node;
        }
    }
    void erase(Node * node)
    {
        if (node == nullptr)
            return;

        if (node->prev_ != nullptr)
            node->prev_->next_ = node->next_;
        if (node->next_ != nullptr)
            node->next_->prev_ = node->prev_;
        if (head_ == node)
            head_ = node->next_;
        if (tail_ == node)
            tail_ = node->prev_;

        // 移除了node之后需要将node的前后指针调整为空
        node->prev_ = node->next_ = nullptr;
    }
    Node* back()
    {
        return tail_;
    }
private:
    Node * head_;
    Node * tail_;
};

class LRUCache
{
public:
    LRUCache(int capacity): capacity_(capacity)
    {
    }

    int get(int key)
    {
        if (map_.find(key) == map_.end())
            return -1;
        Node * node = map_[key];
        list_.erase(node);
        list_.push_front(node);
        return node->val_;
    }

    void put(int key, int value)
    {
        if (map_.find(key) != map_.end())
        {
            Node * node = map_[key];
            list_.erase(node);
            node->val_ = value;
            list_.push_front(node);
        }
        else
        {
            Node * node = new Node(key, value);
            if (size_ == capacity_)
            {
                Node * tail_node = list_.back();
                list_.erase(tail_node);
                map_.erase(tail_node->key_);
                size_--;
            }
            map_[key] = node;
            list_.push_front(node);
            size_++;
        }
    }
private:
    DeList list_;
    map<int, Node*> map_;
    int capacity_{0};
    int size_{0};
};

int main(int argc, char ** argv)
{
    return 0;
}
