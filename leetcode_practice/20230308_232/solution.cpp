#include <stdio.h>
#include <stack>

using std::stack;

class MyQueue
{
public:
    MyQueue()
    {
    }
    
    void push(int x)
    {
        s1.push(x);
    }
    
    int pop()
    {
        transfer();
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek()
    {
        transfer();
        return s2.top();
    }
    
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
private:
    void transfer()
    {
        if (s2.empty() && !s1.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    stack<int> s1;
    stack<int> s2;
};

int main(int argc, char ** argv)
{
    MyQueue q;
    q.push(1);
    q.push(2);
    printf("peek %d\n", q.peek());
    q.pop();
    printf("empty %d\n", q.empty() ? 1 : 0);
    return 0;
}
