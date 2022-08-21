#include <stdio.h>
#include <vector>

using namespace std;

class NumMatrix
{
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0)
        {
            return;
        }
        m_oMatrix = matrix;
        int iSum = matrix[0][0];
        for (int i = 1; i < matrix.size(); i++)
        {
            m_oMatrix[i][0] = iSum + matrix[i][0];
            iSum += matrix[i][0];
        }
        iSum = matrix[0][0];
        for (int j = 1; j < matrix[0].size(); j++)
        {
            m_oMatrix[0][j] = iSum + matrix[0][j];
            iSum += matrix[0][j];
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                m_oMatrix[i][j] = matrix[i][j] + m_oMatrix[i - 1][j] + m_oMatrix[i][j - 1] - m_oMatrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int x = 0, y = 0, z = 0;
        if (row1 - 1 >= 0)
        {
            x = m_oMatrix[row1 - 1][col2];
        }
        if (col1 - 1 >= 0)
        {
            y = m_oMatrix[row2][col1 - 1];
        }
        if (row1 - 1 >= 0 && col1 - 1 >= 0)
        {
            z = m_oMatrix[row1 - 1][col1 - 1];
        }
        return m_oMatrix[row2][col2] - (x + y - z);
    }
private:
    vector<vector<int>> m_oMatrix;
};

int main(int argc, char ** argv)
{
    return 0;
}
