#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        if (m == 0 || n == 0)
            return m + n;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++)
            dp[i][0] = i;
        for (int j = 1; j < n + 1; j++)
            dp[0][j] = j;

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                int m1 = std::min(dp[i][j - 1], dp[i - 1][j]) + 1;
                int m2 = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = std::min(m1, m2);
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
