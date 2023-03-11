#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.size(), len2 = text2.size();
        if (len1 == 0 || len2 == 0)
            return 0;

        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                int a = i > 0 ? dp[i - 1][j] : 0;
                int b = j > 0 ? dp[i][j - 1] : 0;
                int left_up = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;
                int c = text1[i] == text2[j] ? left_up + 1 : left_up;
                dp[i][j] = std::max(std::max(a, b), c);
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};

int main(int argc, char ** argv)
{
    string t1("abcde");
    string t2("ace");
    int ret = Solution().longestCommonSubsequence(t1, t2);
    printf("longestCommonSubsequence ret %d\n", ret);
    return 0;
}
