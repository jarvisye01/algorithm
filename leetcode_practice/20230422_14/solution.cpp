#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    string longestCommonPrefix(vector<string> & strs)
    {
        string result;
        int idx = 0;
        char ch = '0';
        while (true)
        {
            int i = 0;
            for (; i < strs.size();)
            {
                if (strs[i].size() <= idx)
                    break;

                if (ch == '0' || strs[i][idx] == ch)
                    ch = strs[i][idx];
                else
                    break;

                i++;
            }
            if (i < strs.size())
                return result;
            result.push_back(strs[0][idx]);
            idx++;
            ch = '0';
        }
    }
};

int main(int argc, char ** argv)
{
    vector<string> strs{"flower", "flow", "flight"};
    string str = Solution().longestCommonPrefix(strs);
    printf("str %s\n", str.c_str());
    return 0;
}
