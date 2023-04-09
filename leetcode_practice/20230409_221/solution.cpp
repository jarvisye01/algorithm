#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int m = matrix.size(), n = matrix[0].size();
        int max_len = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    max_len = 1;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    continue;
                dp[i][j] = std::min(std::min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                max_len = std::max(max_len, dp[i][j]);
            }
        }
        return max_len * max_len;
    }
};

int main(int argc, char ** argv)
{
    vector<vector<char>> matrix{{'1','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'0','0','1','1','1'}};
    int max_square = Solution().maximalSquare(matrix);
    printf("max_square %d\n", max_square);
    return 0;
}
