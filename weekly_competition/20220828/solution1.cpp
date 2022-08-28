#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
    {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> oTmpVec(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            oTmpVec[i] = {queries[i], 0, i};
        }
        std::sort(oTmpVec.begin(), oTmpVec.end(), [] (auto & x, auto & y) -> bool { return x[0] < y[0]; });

        auto iter = oTmpVec.begin();
        int iTotal = 0, iSubLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (iter == oTmpVec.end())
            {
                break;
            }
            while ((iter != oTmpVec.end()) && (iTotal <= (*iter)[0]) && (iTotal + nums[i] > (*iter)[0]))
            {
                (*iter)[1] = iSubLen;
                iter++;
            }
            iTotal += nums[i];
            iSubLen++;
        }
        while (iter != oTmpVec.end() && iTotal <= (*iter)[0])
        {
            (*iter)[1] = iSubLen;
            iter++;
        }

        vector<int> oResult(queries.size(), 0);
        for (auto iter = oTmpVec.begin(); iter != oTmpVec.end(); iter++)
        {
            oResult[(*iter)[2]] = (*iter)[1];
        }
        return oResult;
    }
};

int main(int argc, char ** argv)
{
    vector<int> oNumVec{4, 5, 2, 1};
    vector<int> oQueries{3, 21, 10};
    vector<int> oResult = Solution().answerQueries(oNumVec, oQueries);
    printf("oResult: ");
    for (int x: oResult)
    {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
