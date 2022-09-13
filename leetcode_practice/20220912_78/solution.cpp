#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> path_vec;
        GetSubSet(nums, 0, path_vec);
        return result_;
    }
private:
    void GetSubSet(const vector<int> & nums, int idx, vector<int> & path_vec)
    {
        result_.push_back(path_vec);
        for (int i = idx; i < nums.size(); i++)
        {
            path_vec.push_back(nums[i]);
            GetSubSet(nums, i + 1, path_vec, path_set);
            path_vec.pop_back();
        }
        return;
    }
private:
    vector<vector<int>> result_;
};

int main(int argc, char ** argv)
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> result = Solution().subsets(nums);
    return 0;
}
