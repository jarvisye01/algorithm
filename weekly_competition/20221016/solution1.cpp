#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxK(vector<int>& nums)
    {
        int ret = -1;
        set<int> num_set;
        for (int i = 0; i < nums.size(); i++)
        {
            num_set.insert(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 && num_set.find(-1 * nums[i]) != num_set.end())
            {
                ret = nums[i] > ret ? nums[i] : ret;
            }
        }
        return ret;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
