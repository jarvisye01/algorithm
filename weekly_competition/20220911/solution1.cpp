#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int mostFrequentEven(vector<int>& nums)
    {
        vector<int> hash(100000 + 1, -1);
        int min_even = -1, min_count = -1;
        for (int x: nums)
        {
            if (hash[x] == -1)
            {
                hash[x] = 0;
            }
            hash[x]++;
        }
        for (int i = 0; i < hash.size(); i++)
        {
            if ((i % 2 != 0) || hash[i] == -1)
            {
                continue;
            }
            if (min_even == -1 || hash[i] > min_count)
            {
                min_even = i;
                min_count = hash[i];
            }
        }
        return min_even;
    }
};

int main(int argc, char ** argv)
{
    vector<int> nums{29,47,21,41,13,37,25,7};
    int count = Solution().mostFrequentEven(nums);
    printf("num: %d\n", count);
    return 0;
}
