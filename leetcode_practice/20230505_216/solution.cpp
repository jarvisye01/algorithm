#include <stdio.h>
#include <set>
#include <vector>

using std::set;
using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> path_vec;
        set<int> path_set;
        CombineAux(k, n, 1, 0, path_vec, path_set);
        return result_;
    }
private:
    void CombineAux(int k, int n, int start_idx, int sum,
            vector<int> & path_vec, set<int> & path_set)
    {
        if (path_vec.size() > k || sum > n)
            return;
        if (path_vec.size() == k && sum == n)
        {
            result_.push_back(path_vec);
            return;
        }
        for (int i = start_idx; i < 10; i++)
        {
            if (path_set.find(i) != path_set.end())
                continue;
            path_vec.push_back(i);
            path_set.insert(i);
            CombineAux(k, n, i + 1, sum + i, path_vec, path_set);
            path_vec.pop_back();
            path_set.erase(i);
        }
        return;
    }
private:
    vector<vector<int>> result_;
};

int main(int argc, char ** argv)
{
    int k = 3, n = 9;
    auto result = Solution().combinationSum3(k, n);
    for (const auto & vec: result)
    {
        printf("Vector: ");
        for (int i = 0; i < vec.size(); i++)
        {
            printf("%d ", vec[i]);
        }
        printf("\n");
    }
    return 0;
}
