#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> & candidates, int target)
    {
        vector<int> path_vec;
        Combine(candidates, target, 0, path_vec, 0);
        return result_;
    }
private:
    void Combine(const vector<int> & candidates, int target, int idx,
            vector<int> & path_vec, int path_sum)
    {
        if (path_sum > target || result_.size() > 150)
            return;
        if (path_sum == target)
        {
            result_.push_back(path_vec);
            return;
        }
        for (int i = idx; i < candidates.size(); i++)
        {
            path_vec.push_back(candidates[i]);
            Combine(candidates, target, i, path_vec, path_sum + candidates[i]);
            path_vec.pop_back();
        }
        return;
    }

    vector<vector<int>> result_;
};

int main(int argc, char ** argv)
{
    vector<int> candidates{2, 3, 6, 7};
    auto result = Solution().combinationSum(candidates, 7);
    for (const auto & vec: result)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            printf("%d ", vec[i]);
        }
        printf("\n");
    }
    return 0;
}
