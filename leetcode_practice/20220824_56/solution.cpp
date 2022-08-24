#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

/*
 * key: 经典的动态规划
 * 这种动态规划有一个特点，dp[i]一定要包含第i个元素，这样的话很容易确定dp[i + 1]
 */
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        int iMax = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = nums[i];
            if (i > 0 && dp[i - 1] > 0)
            {
                dp[i] = dp[i - 1] + nums[i];
            }
            iMax = dp[i] > iMax ? dp[i] : iMax;;
        }
        return iMax;
    }
};

int main(int argc, char ** argv)
{
    vector<int> oNumVec{5, 4, -1, 7, 8};
    int iRet = Solution().maxSubArray(oNumVec);
    printf("iRet %d\n", iRet);
    return 0;
}
