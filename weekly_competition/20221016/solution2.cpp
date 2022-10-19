#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
     int countDistinctIntegers(vector<int>& nums)
     {
         set<int> num_set;
         for (int i = 0; i < nums.size(); i++)
         {
             num_set.insert(nums[i]);
             num_set.insert(reverse(nums[i]));
         }
         return (int)num_set.size();
     }
private:
     int reverse(int num)
     {
         vector<int> data;
         while (num > 0)
         {
             data.push_back(num % 10);
             num /= 10;
         }
         int ret = 0;
         for (int i = 0; i < data.size(); i++)
         {
             ret = ret * 10 + data[i];
         }
         return ret;
     }
};

int main(int argc, char ** argv)
{
    return 0;
}
