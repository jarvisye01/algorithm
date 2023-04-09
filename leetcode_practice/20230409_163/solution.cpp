#include <algorithm>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    // 需要知道为什么排序后的中间元素一定是majority
    int Sort(vector<int> & nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
    // 摩尔投票的做法
    int majorityElement(vector<int> & nums)
    {
        int winner = nums[0], count = 1;;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == winner)
            {
                count++;
            }
            else if (count == 0)
            {
                winner = nums[i];
                count++;
            }
            else
            {
                count--;
            }
        }
        return winner;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{1, 3, 3, 3, 4, 5, 3};
    int winner = Solution().majorityElement(nums);
    printf("winner %d\n", winner);
    return 0;
}
