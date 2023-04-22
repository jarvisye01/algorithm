#include <any>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int findLength(vector<int> & nums1, vector<int> & nums2)
    {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_len = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool is_equal = nums1[i] == nums2[j];
                if (!is_equal)
                    continue;
                int tmp = 1;
                if (i > 0 && j > 0)
                {
                    tmp = dp[i - 1][j - 1] + tmp;
                }
                dp[i][j] = tmp;
                max_len = std::max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums1{1, 2, 3, 2, 1};
    vector<int> nums2{3, 2, 1, 4, 7};
    int ret = Solution().findLength(nums1, nums2);
    printf("ret %d\n", ret);
    return 0;
}
