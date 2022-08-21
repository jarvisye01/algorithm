#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * key: 1.排序之后使用二分查找;
 */
class Solution
{
public:
    int bsearch(const vector<int> & oNumVec, int iLeft, int iRight, int iTarget)
    {
        int iRet = -1;
        if (iLeft >= oNumVec.size())
        {
            return iRet;
        }
        while (iLeft <= iRight)
        {
            int iMid = iLeft + (iRight - iLeft) / 2;
            if (oNumVec[iMid] == iTarget)
            {
                iRet = iMid;
                break;
            }
            else if (oNumVec[iMid] < iTarget)
            {
                iLeft = iMid + 1;
            }
            else
            {
                iRight = iMid - 1;
            }
        }
        return iRet;
    }
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> oResult;
        std::sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
        {
            while (i > 0 && i < sz && nums[i - 1] == nums[i])
            {
                i++;
            }
            for (int j = i + 1; j < sz; j++)
            {
                while (j > i + 1 && j < sz && nums[j - 1] == nums[j])
                {
                    j++;
                }
                if (j >= sz)
                {
                    break;
                }
                int k = bsearch(nums, j + 1, sz - 1, -(nums[i] + nums[j]));
                if (k >= 0)
                {
                    oResult.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return oResult;
    }

    vector<vector<int>> threeSum1(vector<int> & nums)
    {
        vector<vector<int>> oResult;
        std::sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int iLeft = i + 1, iRight = sz - 1;
            while (iLeft < iRight)
            {
                if (nums[iLeft] + nums[iRight] > -nums[i])
                {
                    iRight--;
                }
                else if (nums[iLeft] + nums[iRight] < -nums[i])
                {
                    iLeft++;
                }
                else
                {
                    oResult.push_back({nums[i], nums[iLeft], nums[iRight]});
                    iLeft++;
                    iRight--;
                    while (iLeft < iRight && nums[iLeft - 1] == nums[iLeft])
                    {
                        iLeft++;
                    }
                    while (iRight > iLeft && nums[iRight + 1] == nums[iRight])
                    {
                        iRight--;
                    }
                }
            }
        }
        return oResult;
    }
};

int main(int argc, char ** argv)
{
    vector<int> oNumVec{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> oResult = Solution().threeSum(oNumVec);
    for (const auto & vec: oResult)
    {
        for (int x: vec)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}
