#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int search(vector<int> & nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
