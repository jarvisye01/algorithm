#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
    int rand10()
    {
        int ret = 0;
        do
        {
            ret = (rand2() - 1) * 7 + rand7() - 1;
        }
        while (ret >= 10);
        return ret + 1;
    }
private:
    // [1-2]
    int rand2()
    {
        int ret = 0;
        do
        {
            ret = rand7();
        }
        while (ret > 2);
        return ret;
    }
    // [1-7]
    int rand7()
    {
        return rand() % 7 + 1;
    }
};

int main(int argc, char ** argv)
{
    Solution solution;
    for (int i = 0; i < 100; ++i)
    {
        printf("rand10: %d\n", solution.rand10());
    }
    for (int i = 0; i < 10; ++i)
    {
        printf("test: %d\n", rand() % 10 + 1);
    }
    return 0;
}
