#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool check(vector<vector<int>> & oMatrix, int mid, int k)
    {
        int i = oMatrix.size() - 1, j = 0;
        int count = 0;
        while (i >= 0 && j < oMatrix[0].size())
        {
            if (oMatrix[i][j] < mid)
            {
                count += i + 1;
                j++;
            }
            else
            {
                i--;
            }
        }
        return count < k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right)
        {
            int mid = right - (right - left) / 2;
            if (check(matrix, mid, k))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main(int argc, char ** argv)
{
    vector<vector<int>> oMatrix
    {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int iRet = Solution().kthSmallest(oMatrix, 8);
    printf("iRet %d\n", iRet);
    return 0;
}
