#include <stdio.h>
#include <map>
#include <utility>
#include <vector>

using std::map;
using std::vector;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> count_map;
        for (int x: nums)
        {
            count_map[x]++;
        }
        vector<std::pair<int, int>> data;
        for (const auto & iter: count_map)
        {
            data.push_back(std::make_pair(iter.second, iter.first));
        }
        int left = 0, right = data.size() - 1;
        while (left <= right)
        {
            int pivot = GetPivot(data, left, right);
            if (pivot == k)
            {
                break;
            }
            else if (pivot < k)
            {
                left = pivot + 1;
            }
            else
            {
                right = pivot - 1;
            }
        }
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(data[i].second);
        }
        return result;
    }
private:
    int GetPivot(vector<std::pair<int, int>> & data, int left, int right)
    {
        int i = left + 1, j = right;
        while (i <= j)
        {
            while (i <= right && data[i].first >= data[left].first)
            {
                i++;
            }
            while (j >= left + 1 && data[j].first <= data[left].first)
            {
                j--;
            }
            if (i < j)
            {
                std::swap(data[i], data[j]);
            }
            if (i >= j)
            {
                if (data[j].first > data[left].first)
                {
                    std::swap(data[j], data[left]);
                }
            }
        }
        return j;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
    int k = 2;
    auto result = Solution().topKFrequent(nums, k);
    printf("Vector: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
