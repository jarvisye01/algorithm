#include <stdio.h>
#include <type_traits>
#include <utility>
#include <vector>

using std::vector;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    { 
        int iLeft = 0, iRight = nums.size() - 1;
        k = nums.size() - k;
        while (iLeft <= iRight)
        {
            int iPivot = GetPivot(nums, iLeft, iRight);
            if (iPivot == k)
            {
                return nums[iPivot];
            }
            else if (iPivot < k)
            {
                iLeft = iPivot + 1;
            }
            else
            {
                iRight = iPivot - 1;
            }
        }
        return -1;
    }
private:
    int GetPivot(vector<int> & oNumVec, int iLeft, int iRight)
    {
        int i = iLeft + 1, j = iRight;
        while (i <= j)
        {
            while (i <= iRight && oNumVec[i] <= oNumVec[iLeft])
            {
                i++;
            }
            while (j >= iLeft + 1 && oNumVec[j] >= oNumVec[iLeft])
            {
                j--;
            }
            if (i < j)
            {
                std::swap(oNumVec[i], oNumVec[j]);
            }
            if (i >= j && oNumVec[j] <= oNumVec[iLeft])
            {
                std::swap(oNumVec[iLeft], oNumVec[j]);
            }
        }
        return j;
    }
};

int main(int argc, char ** argv)
{
    vector<int> oNumVec{1, 2, 3, 4, 5, 6};
    for (int i = 0; i < oNumVec.size(); i++)
    {
        printf("k = %d val %d\n", i + 1, Solution().findKthLargest(oNumVec, i + 1));
    }
    return 0;
}
