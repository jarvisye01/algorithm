#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++)
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int j = 1; j < grid[0].size(); j++)
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 1; j < grid[0].size(); j++)
            {
                dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp.back().back();
    }
};

int main(int argc, char ** argv)
{
    vector<vector<int>> grid{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int ret = Solution().minPathSum(grid);
    printf("minPathSum %d\n", ret);
    return 0;
}
