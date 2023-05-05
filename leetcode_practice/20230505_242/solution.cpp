#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> hash(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            hash[static_cast<int>(s[i] - 'a')]++;
            hash[static_cast<int>(t[i] - 'a')]--;
        }
        bool ret = true;
        for (int x: hash)
        {
            if (x != 0)
            {
                ret = false;
                break;
            }
        }
        return ret;
    }
};

int main(int argc, char ** argv)
{
    string s("anagram"), t("nagaram");
    bool ret = Solution().isAnagram(s, t);
    printf("IsAnagram %d\n", static_cast<bool>(ret));
    return 0;
}
