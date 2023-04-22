#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> & matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};

int main(int argc, char ** argv)
{
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    bool ret = Solution().searchMatrix(matrix, 5);
    printf("ret %d\n", static_cast<int>(ret));
    return 0;
}
