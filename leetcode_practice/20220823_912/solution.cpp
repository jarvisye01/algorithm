#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

/*
 * key: quick sort
 */
class Solution
{
public:
    void shuffing(vector<int> & oNumVec)
    {
        srand(time(NULL));
        for (int i = 0; i < oNumVec.size(); i++)
        {
            int iRand = rand() % (oNumVec.size() - i);
            std::swap(oNumVec[i], oNumVec[iRand]);
        }
        return;
    }
    int GetPivot(vector<int> & oNumVec, int iLeft, int iRight)
    {
        int i = iLeft + 1, j = iRight;
        while (i <= j)
        {
            while (i < iRight && oNumVec[i] <= oNumVec[iLeft])
            {
                i++;
            }
            while (j > iLeft && oNumVec[j] >= oNumVec[iLeft])
            {
                j--;
            }
            if (i < j)
            {
                std::swap(oNumVec[i], oNumVec[j]);
            }
            if (i >= j)
            {
                std::swap(oNumVec[iLeft], oNumVec[j]);
                return j;
            }
        }
        return j;
    }

    void sortArray(vector<int> & oNumVec, int iLeft, int iRight)
    {
        if (iLeft >= iRight)
        {
            return;
        }
        int iPos = GetPivot(oNumVec, iLeft, iRight);
        sortArray(oNumVec, iLeft, iPos - 1);
        sortArray(oNumVec, iPos + 1, iRight);
        return;
    }

    vector<int> sortArray(vector<int>& nums)
    {
        shuffing(nums);
        sortArray(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main(int argc, char ** argv)
{
    vector<int> oNumVec{5, 2, 3, 1};
    vector<int> oResult = Solution().sortArray(oNumVec);
    printf("sorted: ");
    for (int x: oResult)
    {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
