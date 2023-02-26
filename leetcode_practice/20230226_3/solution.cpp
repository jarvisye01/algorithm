#include <stdio.h>
#include <algorithm>
#include <set>
#include <string>

using std::set;
using std::string;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        int i = 0, j = 0;
        set<char> char_set;
        int max_len = 0;
        while (j < s.size())
        {
            if (char_set.find(s[j]) == char_set.end())
            {
                char_set.insert(s[j]);
                max_len = std::max(max_len, j - i + 1);
            }
            else
            {
                while (s[i] != s[j])
                {
                    char_set.erase(s[i]);
                    i++;
                }
                // i游标必须要向前一步，此时s[i] == s[j]，但是char_set不用去掉s[i]
                i++;
            }
            j++;
        }
        return max_len;
    }
};

int main(int argc, char ** argv)
{
    string str("pwwkew");
    int max_len = Solution().lengthOfLongestSubstring(str);
    printf("max_len: %d\n", max_len);
    return 0;
}
