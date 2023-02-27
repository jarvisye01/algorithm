#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <type_traits>
#include <utility>
#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        shuffing(nums);
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void shuffing(vector<int> & nums)
    {
        std::srand(time(NULL));
        for (int i = 0; i < nums.size(); i++)
        {
            int n = std::rand() % (nums.size() - i);
            std::swap(nums[i], nums[i + n]);
        }
    }
    void sort(vector<int> & nums, int left, int right)
    {
        if (left >= right)
            return;

        int pivot = GetPivot(nums, left, right);
        sort(nums, left, pivot - 1);
        sort(nums, pivot + 1, right);
    }
    int GetPivot(vector<int> & nums, int left, int right)
    {
        int i = left + 1, j = right;
        while (i <= j)
        {
            while (i <= right && nums[i] <= nums[left])
                i++;
            while (j >= left + 1 && nums[j] >= nums[left])
                j--;

            if (i < j)
                std::swap(nums[i], nums[j]);
            if (i >= j && nums[j] < nums[left])
                std::swap(nums[j], nums[left]);
        }
        return j;
    }
};

int main(int argc, char ** argv)
{
    vector<int> vec{5, 1, 1, 2, 0, 0};
    vector<int> sorted_vec = Solution().sortArray(vec);
    printf("Vector: ");
    for (int i = 0; i < sorted_vec.size(); i++)
    {
        printf("%d ", sorted_vec[i]);
    }
    printf("\n");
    return 0;
}
