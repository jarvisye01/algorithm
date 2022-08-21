#include <stdio.h>
#include <map>
#include <set>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, set<int>> oIdxMap;
        for (int i = 0; i < nums.size(); i++)
        {
            oIdxMap[nums[i]].insert(i);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (target - nums[i] == nums[i] && oIdxMap[nums[i]].size() > 1)
            {
                auto iter = oIdxMap[nums[i]].begin();
                return {*(iter), *(++iter)};
            }
            else if (target - nums[i] != nums[i] && oIdxMap[target - nums[i]].size() > 0)
            {
                return {i, *(oIdxMap[target - nums[i]].begin())};
            }
        }
        return {};
    }
    vector<int> twoSum1(vector<int> & nums, int target)
    {
        map<int, int> oIdxMap;
        // 一次遍历就可以
        for (int i = 0; i < nums.size(); i++)
        {
            if (oIdxMap.find(target - nums[i]) != oIdxMap.end())
            {
                return {oIdxMap.find(target - nums[i])->second, i};
            }
        }
        return {};
    }
};

int main(int argc, char ** argv)
{
    vector<int> oNumVec{2, 7, 11, 15};
    vector<int> oResult = Solution().twoSum(oNumVec, 9);
    if (oResult.size() > 0)
    {
        printf("(%d, %d)\n", oResult[0], oResult[1]);
    }
    return 0;
}
