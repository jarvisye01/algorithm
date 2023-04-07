#include <stdio.h>
#include <utility>
#include <vector>

using std::vector;

class Solution
{
public:
    void rotate(vector<vector<int>> & matrix)
    {
        int len = matrix.size() - 1;
        int limit = matrix.size() / 2;
        if (matrix.size() % 2 == 1)
            limit++;

        for (int i = 0; i < limit; i++)
        {
            vector<std::pair<int, int>> pos{{i, i}, {i, len - i}, {len - i, len - i}, {len - i, i}};
            for (int j = i; j < len - i; j++)
            {
                int a = Get(matrix, pos[0]), b = Get(matrix, pos[1]), c = Get(matrix, pos[2]), d = Get(matrix, pos[3]);
                Set(matrix, pos[0], d);
                Set(matrix, pos[1], a);
                Set(matrix, pos[2], b);
                Set(matrix, pos[3], c);
                pos = GetNext(pos);
            }
        }
        return;
    }
private:
    vector<std::pair<int, int>> GetNext(const vector<std::pair<int, int>> & last_pos)
    {
        vector<std::pair<int, int>> pos;
        pos.push_back({last_pos[0].first, last_pos[0].second + 1});
        pos.push_back({last_pos[1].first + 1, last_pos[1].second});
        pos.push_back({last_pos[2].first, last_pos[2].second - 1});
        pos.push_back({last_pos[3].first - 1, last_pos[3].second});
        return pos;
    }
    int Get(const vector<vector<int>> & matrix, const std::pair<int, int> & pos)
    {
        return matrix[pos.first][pos.second];
    }
    void Set(vector<vector<int>> & matrix, const std::pair<int, int> & pos, int v)
    {
        matrix[pos.first][pos.second] = v;
    }
};

int main(int argc, char ** argv)
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution().rotate(matrix);
    for (const auto vec: matrix)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            printf("%d ", vec[i]);
        }
        printf("\n");
    }
    return 0;
}
