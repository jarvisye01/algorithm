#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int iHead = 1, iTail = 1;
        vector<int> oHeadVec(nums.size(), 0), oTailVec(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            iHead *= nums[i], iTail *= nums[nums.size() - i - 1];
            oHeadVec[i] = iHead;
            oTailVec[nums.size() - i - 1] = iTail;
        }

        vector<int> oResult(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int iLeft = 1, iRight = 1;
            if (i > 0)
            {
                iLeft = oHeadVec[i - 1];
            }
            if (i < nums.size() - 1)
            {
                iRight = oTailVec[i + 1];
            }
            oResult[i] = iLeft * iRight;
        }
        return oResult;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
