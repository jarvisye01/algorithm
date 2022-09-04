#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkDistances(string s, vector<int>& distance)
    {
        vector<int> char_arr(26, -1);
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            int idx = ch - 'a';
            if (char_arr[idx] == -1)
            {
                char_arr[idx] = i;
            }
            else
            {
                char_arr[idx] = i - char_arr[idx] - 1;
            }
        }
        for (int i = 0; i < char_arr.size(); ++i)
        {
            if (char_arr[i] != -1 && char_arr[i] != distance[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char ** argv)
{
    string s("abaccb");
    vector<int> distance{1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool ret = Solution().checkDistances(s, distance);
    printf("ret %d\n", ret ? 1 : 0);
    return 0;
}
