#include <stdio.h>
#include <vector>

using namespace std;

const int MAX = 1000000000 + 7;

class Solution
{
public:
    // 二维dp数据，需要一定的临场应变能力
    int numberOfWays(int startPos, int endPos, int k)
    {
        if (endPos - startPos > k)
        {
            return 0;
        }
        vector<vector<int>> dp(2 * k + 1);
        for (int i = 0; i < dp.size(); i++)
        {
            dp[i].resize(k + 1, 0);
        }
        dp[k + endPos - startPos][0] = 1;
        for (int col = 1; col < k + 1; col++)
        {
            for (int row = 0; row < 2 * k + 1; row++)
            {
                int a = 0, b = 0;
                if (row - 1 >= 0)
                {
                    a = dp[row- 1][col -1];
                }
                if (row + 1 < 2 * k + 1)
                {
                    b = dp[row + 1][col - 1];
                }
                dp[row][col] = (a + b) % MAX;
            }
        }
        return dp[k][k];
    }
};

int main(int argc, char ** argv)
{
    int start = 1, end = 1000, k = 999;
    int count = Solution().numberOfWays(start, end, k);
    printf("count %d\n", count);
    return 0;
}
