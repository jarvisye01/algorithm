#include <algorithm>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    int trap(vector<int> & height)
    {
        int result = 0;
        if (height.size() == 0)
            return result;

        int len = height.size();
        vector<int> arr1(height), arr2(height);
        for (int i = 1; i < len - 1; i++)
        {
            arr1[i] = std::max(arr1[i - 1], height[i]);
            arr2[len - 1 - i] = std::max(arr2[len - i], height[len - 1 - i]);
        }

        for (int i = 1; i < len - 1; i++)
        {
            int max = std::min(arr1[i], arr2[i]);
            if (max > height[i])
                result += max - height[i];
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int result = Solution().trap(height);
    printf("result: %d\n", result);
    return 0;
}
