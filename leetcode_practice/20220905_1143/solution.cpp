#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int max = 0;
        if (text1.size() == 0 || text2.size() == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                int a = 0, b = 0, c = 0;
                a = i > 0 ? dp[i - 1][j] : a;
                b = j > 0 ? dp[i][j - 1] : b;
                c = i > 0 && j > 0 ? dp[i - 1][j - 1] : c;
                dp[i][j] = text1[i] == text2[j] ? c + 1 : std::max(a, b);
                max = std::max(max, dp[i][j]);
            }
        }
        return max;
    }
};

int main(int argc, char ** argv)
{
    string s1("abcde"), s2("ace");
    int ret = Solution().longestCommonSubsequence(s1, s2);
    printf("ret %d\n", ret);
    return 0;
}
