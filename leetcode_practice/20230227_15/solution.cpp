#include <algorithm>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> & nums)
    {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            // 防止重复
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > 0)
                break;

            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    // 防止重复
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (k > j && nums[k] == nums[k + 1])
                        k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = Solution().threeSum(vec);
    for (const auto & vec: result)
    {
        printf("Vector: ");
        for (int i = 0; i < vec.size(); i++)
        {
            printf("%d ", vec[i]);
        }
        printf("\n");
    }
    return 0;
}
