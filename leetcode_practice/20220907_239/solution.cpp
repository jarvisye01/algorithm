#include <stdio.h>
#include <deque>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (nums.size() < 2)
        {
            return nums;
        }
        vector<int> result(nums.size() - k + 1);
        deque<int> num_queue;
        for (int i = 0; i < nums.size(); i++)
        {
            while (num_queue.size() > 0 && nums[i] >= nums[num_queue.back()])
            {
                num_queue.pop_back();
            }
            num_queue.push_back(i);
            while (num_queue.size() > 0 && num_queue.front() < i - k + 1)
            {
                num_queue.pop_front();
            }
            if (i >= k - 1)
            {
                result[i - k + 1] = nums[num_queue.front()];
            }
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{7, 2, 4};
    vector<int> result = Solution().maxSlidingWindow(nums, 2);
    printf("Vector: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
