#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> searchRange(vector<int> & nums, int target)
    {
        vector<int> result{-1, -1};
        if (nums.size() == 0)
            return result;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        result[0] = nums[left] == target ? left : -1;

        left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = right - (right - left) / 2;
            if (nums[mid] == target)
                left = mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        result[1] = nums[right] == target ? right : -1;
        return result;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;
    auto result = Solution().searchRange(nums, target);
    printf("Vector: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
