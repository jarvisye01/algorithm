#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char ** argv)
{
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
    int min_path = Solution().minPathSum(grid);
    printf("min_path: %d\n", min_path);
    return 0;
}
