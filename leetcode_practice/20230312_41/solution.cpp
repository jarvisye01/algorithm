#include <stdio.h>
#include <type_traits>
#include <vector>

using std::vector;

class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        if (nums.size() <= 0)
            return 1;
        for (int i = 0; i < nums.size(); i++)
        {
            while ((nums[i] > 0 && nums[i] <= nums.size()) &&
                    (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]))
            {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }

};

int main(int argc, char ** argv)
{
    vector<int> nums{3, 4, -1, 1};
    int ret = Solution().firstMissingPositive(nums);
    printf("ret %d\n", ret);
    return 0;
}
