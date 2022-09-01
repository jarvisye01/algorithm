#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        can_finish_ = true;
        marked_.resize(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (const auto & vec: prerequisites)
        {
            graph[vec[1]].push_back(vec[0]);
        }
        for (int v = 0; v < numCourses; v++)
        {
            dfs(graph, v);
        }
        if (can_finish_)
        {
            std::reverse(result_.begin(), result_.end());
            return result_;
        }
        return {};
    }
private:
    void dfs(vector<vector<int>> & graph, int v)
    {
        if (marked_[v] == 2)
        {
            return;
        }
        marked_[v] = 1;
        const auto & adj_vec = graph[v];
        for (int w: adj_vec)
        {
            if (marked_[w] == 0)
            {
                dfs(graph, w);
                if (!can_finish_)
                {
                    return;
                }
            }
            else if (marked_[w] == 1)
            {
                can_finish_ = false;
                return;
            }
        }
        marked_[v] = 2;
        result_.push_back(v);
    }
private:
    vector<int> result_;
    vector<int> marked_;
    bool can_finish_;
};

int main(int argc, char ** argv)
{
    return 0;
}
