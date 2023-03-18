#include <stdint.h>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int coinChange(vector<int> & coins, int amount)
    {
        int ret = 0;
        vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; i++)
        {
            int y = -1;
            for (int c: coins)
            {
                if (i - c >= 0 && dp[i - c] != -1)
                {
                    y = (y == -1) ? dp[i -c] + 1 : std::min(y, dp[i - c] + 1);
                }
            }
            dp[i] = y;
        }
        return dp[amount];
    }
};

int main(int argc, char ** argv)
{
    vector<int> coins{1, 2, 5};
    printf("CoinChange %d\n", Solution().coinChange(coins, 11));
    return 0;
}
