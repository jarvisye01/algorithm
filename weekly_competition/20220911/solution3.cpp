#include <stdio.h>

#include <algorithm>
#include <functional>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), [] (const vector<int> & v1, const vector<int> & v2) -> bool { return v1[0] < v2[0]; });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto & vec: intervals)
        {
            if (!pq.empty() && pq.top() < vec[0])
            {
                pq.pop();
            }
            pq.push(vec[1]);
        }
        return pq.size();
    }
};

int main(int argc, char ** argv)
{
    vector<vector<int>> intervals{{229966,812955},{308778,948377},{893612,952735}};
    int count = Solution().minGroups(intervals);
    printf("count: %d\n", count);
    return 0;
}
