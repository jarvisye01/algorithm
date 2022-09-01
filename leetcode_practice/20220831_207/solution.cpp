#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<set<int>> oGraph(numCourses);
        for (const auto & vec: prerequisites)
        {
            oGraph[vec[1]].insert(vec[0]);
        }

        bCanFinish = true;
        vector<int> oMarked(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (oGraph[i].size() > 0)
            {
                dfs(oGraph, i, oMarked);
            }
        }
        return bCanFinish;
    }
private:
    void dfs(vector<set<int>> & oGraph, int v, vector<int> & oMarked)
    {
        oMarked[v] = 1;
        const set<int> & oAdjSet = oGraph[v];
        for (int w: oAdjSet)
        {
            if (oMarked[w] == 0)
            {
                dfs(oGraph, w, oMarked);
                if (!bCanFinish)
                {
                    return;
                }
            }
            else if (oMarked[w] == 1)
            {
                bCanFinish = false; 
                return;
            }
        }
        oMarked[v] = 2;
    }
private:
    bool bCanFinish;
};

int main(int argc, char ** argv)
{
    return 0;
}
