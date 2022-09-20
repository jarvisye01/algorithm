#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                vector<vector<int>> visited(row, vector<int>(col, 0));
                if (Check(board, word, i, j, 0, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool Check(const vector<vector<char>> & board, const string & word, int i, int j, int idx, vector<vector<int>> & visited)
    {
        if (idx >= word.size())
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[idx])
        {
            return false;
        }
        visited[i][j] = 1;
        if (Check(board, word, i + 1, j, idx + 1, visited))
        {
            return true;
        }
        if (Check(board, word, i - 1, j, idx + 1, visited))
        {
            return true;
        }
        if (Check(board, word, i, j + 1, idx + 1, visited))
        {
            return true;
        }
        if (Check(board, word, i, j - 1, idx + 1, visited))
        {
            return true;
        }
        visited[i][j] = 0;
        return false;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
