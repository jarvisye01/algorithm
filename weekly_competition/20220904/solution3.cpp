#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestNiceSubarray(vector<int>& nums)
    {
        int ret = 0;
        if (nums.size() == 0)
        {
            return ret;
        }
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            int k = 0;
            for (; k < dp[i - 1]; k++)
            {
                if ((nums[i] & nums[i - 1 - k]) != 0)
                {
                    break;
                }
            }
            dp[i] = k + 1;
        }
        auto iter = std::max_element(dp.begin(), dp.end());
        ret = *iter;
        return ret;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{84139415, 693324769, 614626365, 497710833, 615598711, 264, 65552, 50331652, 1, 1048576, 16384, 544, 270532608, 151813349, 221976871, 678178917, 845710321, 751376227, 331656525, 739558112, 267703680};
    int ret = Solution().longestNiceSubarray(nums);
    printf("ret %d\n", ret);
    return 0;
}
