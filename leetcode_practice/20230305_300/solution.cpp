#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int len = nums.size();
        vector<int> tail;
        tail.push_back(nums[0]);

        for (int i = 1; i < len; i++)
        {
            if (nums[i] > tail.back())
            {
                tail.push_back(nums[i]);
                continue;
            }

            // 重点是找到tail中第一个大于或者等于nums[i]的数字,必然是存在的
            int left = 0, right = tail.size() - 1;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (tail[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid; // right保持在mid上，而不是移动到mid的左边
            }
            // 将第一个大于等于nums[i]的数替换成nums[i]
            tail[left] = nums[i];
        }
        return tail.size();
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
