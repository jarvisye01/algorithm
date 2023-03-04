#include <stdio.h>
#include <set>
#include <vector>

using std::set;
using std::vector;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> & nums)
    {
        vector<int> path;
        set<int> path_set;
        permute_(nums, path, path_set);
        return this->res_;
    }
private:
    void permute_(const vector<int> & nums, vector<int> & path, set<int> & path_set)
    {
        if (path.size() == nums.size())
        {
            res_.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (path_set.find(nums[i]) == path_set.end())
            {
                path.push_back(nums[i]);
                path_set.insert(nums[i]);
                permute_(nums, path, path_set);
                path.pop_back();
                path_set.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> res_;
};

int main(int argc, char ** argv)
{
    vector<int> vec{1, 2, 3};
    auto res = Solution().permute(vec);
    for (const auto & v: res)
    {
        printf("Vector: ");
        for (int i = 0; i < v.size(); i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    return 0;
}
