#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n ; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(int argc, char ** argv)
{
    int result = Solution().climbStairs(5);
    printf("result %d\n", result);
    return 0;
}
