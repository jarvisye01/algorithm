#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        int count = 0;
        int len = time.size();
        vector<int> data(60, 0);
        for (int t: time)
        {
            data[t % 60]++;
        }
        // 很巧妙的一个做法，可能需要背一下
        // 对于需要取模的题目一般都会有特殊的解法
        for (int i = 1; i <= 29; i++)
        {
            count += data[i] * data[60 - i];
        }
        auto get = [] (long long x) -> int {
            if (x == 0)
                return static_cast<int>(x);
            return static_cast<int>((x * (x - 1)) / 2);
        };
        count += get(data[0]) + get(data[30]);
        return count;
    }
};

int main(int argc, char ** argv)
{
    vector<int> time;
    for (int i = 0; i < 60000; i++)
    {
        time.push_back(60);
    }
    int ret = Solution().numPairsDivisibleBy60(time);
    printf("ret %d\n", ret);
    return 0;
}
