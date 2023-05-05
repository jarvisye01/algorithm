#include <algorithm>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> & logs)
    {
        int worker = logs[0][0], longest_time = logs[0][1];
        for (int i = 1; i < logs.size(); i++)
        {
            int t_time = logs[i][1] - logs[i - 1][1];
            if (t_time > longest_time)
            {
                worker = logs[i][0];
                longest_time = t_time;
            }
            else if (t_time == longest_time)
            {
                worker = std::min(worker, logs[i][0]);
            }
        }
        return worker;
    }
};

int main(int argc, char ** argv)
{
    int n = 26;
    vector<vector<int>> logs{{1, 1}, {3, 7}, {2, 12}, {7, 17}};
    int worker = Solution().hardestWorker(n, logs);
    printf("HardestWorker %d\n", worker);
    return 0;
}
