#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    // Solution: https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/solution/jian-ji-xie-fa-pythonjavacgo-by-endlessc-gag2/
    // 通过枚举右端点来进行计算
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        long long ret = 0;
        int min_index = -1, max_index = -1, zero = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == minK)
                min_index = i;
            if (nums[i] == maxK)
                max_index = i;
            if (nums[i] < minK || nums[i] > maxK)
                zero = i;
            ret += std::max(std::min(min_index, max_index) - zero, 0);
        }
        return ret;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{1, 3, 5, 2, 7, 5};
    auto ret = Solution().countSubarrays(nums, 1, 5);
    printf("countSubarrays ret: %ld\n", ret);
    return 0;
}
