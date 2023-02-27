#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int maxSubArray(vector<int> & nums)
    {
        if (nums.size() == 0)
            return 0;

        vector<int> dp(nums.size(), 0);
        int max_sub = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = nums[i];
            if (i > 0 && dp[i - 1] > 0)
                dp[i] += dp[i - 1];

            max_sub = std::max(dp[i], max_sub);
        }
        return max_sub;
    }
};

int main(int argc, char ** argv)
{
    vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sub = Solution().maxSubArray(vec);
    printf("max_sub %d\n", max_sub);
    return 0;
}
