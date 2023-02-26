#include <stdio.h>
#include <type_traits>
#include <vector>

using std::vector;

/*
 * 1.采用quick sort；
 * 2.采用big heap；
 */
class Solution
{
public:
    int findKthLargest0(vector<int>& nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        k = nums.size() - k;
        while (left <= right)
        {
            int pivot = GetPivot(nums, left, right);
            if (pivot == k)
                return nums[pivot];
            else if (pivot < k)
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        return -1;
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        int heapsize = nums.size();
        BuildHeap(nums, heapsize);
        for (int i = 0; i < k - 1; i++)
        {
            std::swap(nums[0], nums[heapsize - 1]);
            heapsize--;
            MaxHeapify(nums, 0, heapsize);
        }
        return nums[0];
    }
private:
    void MaxHeapify(vector<int> & nums, int i, int heapsize)
    {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapsize && nums[l] > nums[largest])
            largest = l;
        if (r < heapsize && nums[r] > nums[largest])
            largest = r;

        if (largest != i)
        {
            std::swap(nums[i], nums[largest]);
            MaxHeapify(nums, largest, heapsize);
        }
    }

    void BuildHeap(vector<int> & nums, int heapsize)
    {
        for (int i = heapsize / 2 - 1; i >= 0; i--)
        {
            MaxHeapify(nums, i, heapsize);
        }
    }

    int GetPivot(vector<int> & num_vec, int left, int right)
    {
        int i = left + 1, j = right;
        int num = num_vec[left];
        while (i <= j)
        {
            while (i <= right && num_vec[i] <= num)
            {
                i++;
            }
            while (j >= left + 1 && num_vec[j] >= num)
            {
                j--;
            }
            if (i < j)
            {
                std::swap(num_vec[i], num_vec[j]);
            }
            if (i >= j && num_vec[j] <= num)
            {
                std::swap(num_vec[j], num_vec[left]);
            }
        }
        return j;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
