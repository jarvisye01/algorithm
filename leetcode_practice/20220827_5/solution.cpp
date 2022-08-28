#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

/*
 * 1.这道题目就是O(n^2)，正常做就行了;
 * 2.不要想太多;
 */
class Solution
{
public:
    int expandLen(const string & s, int i, int j, vector<int> & pos)
    {
        if (i < 0 || j >= s.size() || i > j)
        {
            return -1;
        }
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
        pos = {++i, --j};
        return j - i + 1;
    }
    string longestPalindrome(string s)
    {
        int len = 0, start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> pos1, pos2;
            int len1 = expandLen(s, i, i, pos1), len2 = 0;
            if (i + 1 < s.size())
            {
                len2 = expandLen(s, i, i + 1, pos2);
            }
            if (len1 > len2 && len1 > len)
            {
                len = std::max(len, len1);
                start = pos1[0], end = pos1[1];
            }
            else if (len2 > len)
            {
                len = std::max(len, len2);
                start = pos2[0], pos2[1];
            }
        }
        return s.substr(start, len);
    }
};

int main(int argc, char ** argv)
{
    string s("babad");
    string str = Solution().longestPalindrome(s);
    printf("str: %s\n", str.c_str());
    return 0;
}
