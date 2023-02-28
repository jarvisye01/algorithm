#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int idx = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                // 常理是移动left，只有一种特殊情况需要移动right
                if (target > nums[right] && nums[mid] <= nums[right])
                    right = mid - 1;
                else
                    left =  mid + 1;
            }
            else
            {
                // 常理是移动right，只有一种特殊情况需要移动left
                if (target < nums[left] && nums[mid] >= nums[left])
                    left = mid + 1;
                else
                    right = mid - 1;

            }
        }
        return idx;
    }
};

int main(int argc, char ** argv)
{
    vector<int> vec{4, 5, 6, 7, 0, 1, 2};
    int idx = Solution().search(vec, 0);
    printf("idx %d\n", idx);
    return 0;
}
