#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left = Search(nums, target, 0);
        int right = Search(nums, target, 1);
        return {left, right};
    }
private:
    // binary search
    int Search(vector<int> & nums, int target, int direct)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                if (direct == 0 && (mid > 0 && nums[mid - 1] == target))
                {
                    right = mid - 1;
                }
                else if (direct == 1 && (mid < nums.size() - 1 && nums[mid + 1] == target))
                {
                    left = mid + 1;
                }
                else
                {
                    return mid;
                }
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{5, 7, 7, 8, 8, 10};
    vector<int> range = Solution().searchRange(nums, 8);
    printf("range: (%d, %d)\n", range[0], range[1]);
    return 0;
}
