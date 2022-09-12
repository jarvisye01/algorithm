#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

// segment tree
class SegmentTree
{
public:
    void Build(int sz)
    {
        size = sz;
        tree_arr.resize(size * 4, 0);
        Build(1, 1, size);
    }
    void Build(int root, int left, int right)
    {
        if (left == right)
        {
            tree_arr[root] = 0;
            return;
        }
        int mid = (left + right) / 2;
        Build(root << 1, left, mid);
        Build(root << 1 | 1, mid + 1, right);
        tree_arr[root] = std::max(tree_arr[root << 1], tree_arr[root << 1 | 1]);
        return;
    }
    int Query(int l, int r)
    {
        return Query(1, 1, size, l, r);
    }
    int Query(int root, int left, int right, int l, int r)
    {
        if (r < left || l > right)
        {
            return 0;
        }
        if (l <= left && r >= right)
        {
            return tree_arr[root];
        }
        int mid = (left + right) / 2;
        int ql = Query(root << 1, left, mid, l, r);
        int qr = Query(root << 1 | 1, mid + 1, right, l, r);
        return std::max(ql, qr);
    }
    void Modify(int pos, int val)
    {
        Modify(1, 1, size, pos, val);
    }
    void Modify(int root, int left, int right, int pos, int val)
    {
        if (left == right && left == pos)
        {
            tree_arr[root] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (pos >= left && pos <= mid)
        {
            Modify(root << 1, left, mid, pos, val);
        }
        if (pos >= mid + 1 && pos <= right)
        {
            Modify(root << 1 | 1, mid + 1, right, pos, val);
        }
        tree_arr[root] = std::max(tree_arr[root << 1], tree_arr[root << 1 | 1]);
        return;
    }
private:
    int size;
    vector<int> tree_arr;
};

// 考察数据结构segment tree
class Solution
{
public:
    // O(n^2) 无法通过测试用例
    int lengthOfLIS(vector<int>& nums, int k)
    {
        int max_element = *std::max_element(nums.begin(), nums.end());
        SegmentTree st;
        st.Build(max_element * 4);
        for (int i = 0; i < nums.size(); i++)
        {
            // query
            if (nums[i] == 1)
            {
                st.Modify(1, 1);
            }
            else
            {
                int tmp = 1 + st.Query(std::max(nums[i] - k, 1), nums[i] - 1);
                st.Modify(nums[i], tmp);
            }
        }
        return st.Query(1, max_element);
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{4, 2, 1, 4, 3, 4, 5, 8, 15};
    int ret = Solution().lengthOfLIS(nums, 3);
    printf("ret %d\n", ret);
    return 0;
}
