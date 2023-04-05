#include <stdio.h>
#include <stdlib.h>

class Solution
{
public:
    int rand10()
    {
        int x = 0;
        while (true)
        {
            x = ((rand7() - 1) * 7) + rand7(); // get a num in [1, 49]
            if (x <= 40)
                break;
        }
        return x % 10 + 1;
    }

    int rand7()
    {
        return rand() % 7 + 1;
    }
};

int main(int argc, char ** argv)
{
    for (int i = 0; i < 100; i++)
    {
        printf("rand10() = %d\n", Solution().rand10());
    }
    return 0;
}
