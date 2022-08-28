#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        if (nums.size() <= 1)
        {
            return;
        }
        int iMaxIdx = nums.size() - 1, iIdx = nums.size() - 2;
        while (iIdx >= 0)
        {
            if (nums[iIdx] < nums[iMaxIdx])
            {
                for (int i = iMaxIdx + 1; i < nums.size(); i++)
                {
                    if (nums[i] > nums[iIdx] && nums[i] < nums[iMaxIdx])
                    {
                        iMaxIdx = i;
                    }
                }
                break;
            }
            else if (nums[iIdx] > nums[iMaxIdx])
            {
                iMaxIdx = iIdx;
            }
            iIdx--;
        }
        if (iIdx >= 0)
        {
            std::swap(nums[iMaxIdx], nums[iIdx]);
        }
        // 优化，这里可以替换成reverse，面试的小技巧;
        std::sort(nums.begin() + iIdx + 1, nums.end());
        return;
    }
};

int main(int argc, char ** argv)
{
    vector<int> oNumVec{3, 2, 1};
    Solution().nextPermutation(oNumVec);
    printf("Vector: ");
    for (int i = 0; i < oNumVec.size(); i++)
    {
        printf("%d ", oNumVec[i]);
    }
    printf("\n");
    return 0;
}
