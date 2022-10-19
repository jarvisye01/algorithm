#include <cstddef>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    // 暴力法
    int subarraySum1(vector<int>& nums, int k)
    {
        int count = 0;
        vector<int> note(nums.size(), 0);
        int pre_sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            note[i] = pre_sum + nums[i];
            pre_sum = note[i];
            if (note[i] == k)
                count++;
        }
        for (size_t i = 1; i < nums.size(); i++)
        {
            for (size_t j = i; j < nums.size(); j++)
            {
                note[j] = note[j] - nums[i - 1];
                if (note[j] == k)
                    count++;
            }
        }
        return count;
    }
    // hash优化
    int subarraySum(vector<int>& nums, int k)
    {
        int count = 0;
        map<int, int> hash;
        hash[0]++;
        int pre_sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            pre_sum += nums[i];
            if (hash.find(pre_sum - k) != hash.end())
            {
                count += hash.find(pre_sum - k)->second;
            }
            hash[pre_sum]++;
        }
        return count;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{1, 2, 3, 4};
    int ret = Solution().subarraySum(nums, 3);
    printf("subarraySum ret: %d\n", ret);
    return 0;
}
