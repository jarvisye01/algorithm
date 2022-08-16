#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int iRet = 0;
        map<int, int> oMap;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                oMap[nums1[i] + nums2[j]]++;
            }
        }

        for (int i = 0; i < nums3.size(); i++)
        {
            for (int j = 0; j < nums4.size(); j++)
            {
                if (oMap.find(-(nums3[i] + nums4[j])) != oMap.end())
                {
                    iRet += oMap[-(nums3[i] + nums4[j])];
                }
            }
        }
        return iRet;
    }
};

int main(int argc, char ** argv)
{
    vector<int> oNums1{1, 2};
    vector<int> oNums2{-2, -1};
    vector<int> oNums3{-1, 2};
    vector<int> oNums4{0, 2};
    int iRet = Solution().fourSumCount(oNums1, oNums2, oNums3, oNums4);
    printf("iRet %d\n", iRet);
    return 0;
}
