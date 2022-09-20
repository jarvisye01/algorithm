#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int i = matrix.size() - 1, j = 0, col_max = matrix[0].size();
        while (i >= 0 && j < col_max)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] < target)
            {
                ++j;
            }
            else
            {
                --i;
            }
        }
        return false;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
