#include <stdio.h>
#include <algorithm>
#include <type_traits>
#include <vector>

using std::vector;

class Solution
{
public:
    void nextPermutation1(vector<int> & nums)
    {
        if (nums.size() <= 1)
            return;
        // 假设最后一对是一对顺序对
        int max_idx = nums.size() - 1, idx = nums.size() - 2;
        while (idx >= 0)
        {
            if (nums[idx] < nums[max_idx])
            {
                for (int i = max_idx + 1; i < nums.size(); i++)
                {
                    if (nums[idx] < nums[i] && nums[i] < nums[max_idx])
                    {
                        max_idx = i;
                    }
                }
                break;
            }
            else if (nums[idx] > nums[max_idx])
            {
                // 因为要找第一对顺序对nums[x] < nums[y]，这里保持nums[y]足够大才行
                max_idx = idx;
            }
            idx--;
        }
        if (idx >= 0)
            std::swap(nums[idx], nums[max_idx]);
        // idx和max_idx交换之后，后续的数组需要进行重排序
        std::sort(nums.begin() + 1 + idx, nums.end());
        return;
    }
    // 经典题解，太巧妙了
    void nextPermutation(vector<int> & nums)
    {
        if (nums.size() <= 1)
            return;
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j > i && nums[j] <= nums[i])
                j--;
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + 1 + i, nums.end());
    }
};

int main(int argc, char ** argv)
{
    vector<int> vec{1, 5, 3, 2, 0};
    Solution().nextPermutation(vec);
    printf("Vector: ");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
    return 0;
}
