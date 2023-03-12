#include <stdio.h>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> result;
        if (nums.size() < k)
            return result;
        priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});

        result.push_back(pq.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
            while (pq.top().second < i - k + 1)
                pq.pop();
            result.push_back(pq.top().first);
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    auto result = Solution().maxSlidingWindow(nums, 3);
    printf("Vector: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
