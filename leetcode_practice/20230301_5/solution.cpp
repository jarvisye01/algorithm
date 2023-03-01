#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> pos1, pos2;
            int len1 = expand(s, i, i, pos1);
            int len2 = expand(s, i, i + 1, pos2);
            if (len1 >= len2 && len1 > len)
                start = pos1[0], len = len1;
            else if (len2 > len1 && len2 > len)
                start = pos2[0], len = len2;
        }
        return s.substr(start, len);
    }
private:
    int expand(const string & s, int i, int j, vector<int> & pos)
    {
        if (i < 0 || j >= s.size() || i > j)
            return -1;
        while (i >= 0 && j < s.size() && s[i] == s[j])
            i--, j++;
        pos = {++i, --j};
        return j - i + 1;
    }
};

int main(int argc, char ** argv)
{
    string s("babad");
    printf("res %s\n", Solution().longestPalindrome(s).c_str());
    return 0;
}
