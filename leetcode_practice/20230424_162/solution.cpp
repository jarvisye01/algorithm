#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int findPeakElement(vector<int> & nums)
    {
        int len = nums.size();
        int left = 0, right = len - 1, result = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                    (mid == len - 1 || nums[mid] > nums[mid + 1]))
            {
                result = mid;
                break;
            }
            if (mid == len - 1 || nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{1, 2, 3, 1};
    int result = Solution().findPeakElement(nums);
    printf("result %d\n", result);
    return 0;
}
