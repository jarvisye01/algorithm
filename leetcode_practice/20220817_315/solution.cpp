#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

/*
 * 1.merge归并排序；
 * 2.用一个索引数据记录最初的位置；
 */
class Solution
{
public:
    void merge(vector<int> & oNums, int iLeft, int iRight, vector<int> & oResult)
    {
        if (iLeft >= iRight)
        {
            return;
        }

        int iMid = iLeft + (iRight - iLeft) / 2;
        merge(oNums, iLeft, iMid, oResult);
        merge(oNums, iMid + 1, iRight, oResult); 
        int i = iLeft, k = iMid + 1;
        int iCount = 0;
        vector<int> oTmpVec;
        while (i < iMid + 1 && k < iRight + 1)
        {
            if (oNums[i] > oNums[k])
            {
                m_oTmpPos[iLeft + iCount] = m_oPos[k];
                oTmpVec.push_back(oNums[k]);
                k++;
            }
            else
            {
                m_oTmpPos[iLeft + iCount] = m_oPos[i];
                oResult[m_oPos[i]] += k - (iMid + 1);
                oTmpVec.push_back(oNums[i]);
                i++;
            }
            iCount++;
        }
        while (i < iMid + 1)
        { 
            m_oTmpPos[iLeft + iCount] = m_oPos[i];
            oResult[m_oPos[i]] += k - (iMid + 1);
            oTmpVec.push_back(oNums[i]);
            i++;
            iCount++;
        }
        while (k < iRight + 1)
        {
            m_oTmpPos[iLeft + iCount] = m_oPos[k];
            oTmpVec.push_back(oNums[k]);
            k++;
            iCount++;
        }
        int iIdx = iLeft;
        for (int x: oTmpVec)
        {
            oNums[iIdx] = x;
            m_oPos[iIdx] = m_oTmpPos[iIdx];
            iIdx++;
        }
        return;
    }
    vector<int> countSmaller(vector<int>& nums)
    {
        m_oPos.resize(nums.size());
        m_oTmpPos.resize(nums.size());
        vector<int> oResult(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            m_oPos[i] = i;
            m_oTmpPos[i] = i;
        }
        merge(nums, 0, nums.size() - 1, oResult);
        return oResult;
    }
private:
    vector<int> m_oPos;
    vector<int> m_oTmpPos;
};

int main(int argc, char ** argv)
{
    vector<int> oNumVec{5, 2, 6, 1};
    vector<int> oResult = Solution().countSmaller(oNumVec);
    printf("oResult: ");
    for (int x: oResult)
    {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
