#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        if (intervals.size() == 0)
            return result;

        std::sort(intervals.begin(), intervals.end(), [] (const auto & x, const auto & y) -> bool { return x[0] < y[0]; });
        int left = 0, right = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (i == 0)
            {
                left = intervals[i][0];
                right = intervals[i][1];
                continue;
            }

            if (right >= intervals[i][0])
            {
                right = std::max(right, intervals[i][1]);
            }
            else
            {
                result.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        if (result.size() == 0 || left > result.back()[1])
            result.push_back({left, right});
        return result;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
