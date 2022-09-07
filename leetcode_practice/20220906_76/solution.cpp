#include <stdio.h>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // init
        unordered_map<char, int> char_hash, tmp_hash;
        set<char> char_set, tmp_set;
        for (char ch: t)
        {
            char_hash[ch]++;
            char_set.insert(ch);
        }

        // two pointer
        string result;
        int start = 0, end = 0;
        for (; end < s.size(); end++)
        {
            char ch = s[end];
            if (char_hash.find(ch) != char_hash.end())
            {
                tmp_hash[ch]++;
                if (tmp_hash[ch] >= char_hash[ch])
                {
                    tmp_set.insert(ch);
                }
            }
            if (char_set.size() == tmp_set.size())
            {
                for (; start <= end; start++)
                {
                    char ch = s[start];
                    if (char_set.find(ch) == char_set.end())
                    {
                        continue;
                    }
                    if (tmp_hash[ch] > char_hash[ch])
                    {
                        tmp_hash[ch]--;
                    }
                    else
                    {
                        break;
                    }
                }
                if (result.size() == 0 || (end - start + 1) < result.size())
                {
                    result = s.substr(start, end - start + 1);
                }
                tmp_set.erase(s[start]);
                tmp_hash[s[start]]--;
                start++;
            }
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    string s = "ADOBECODEBANC", t = "ABC";
    string res = Solution().minWindow(s, t);
    printf("res %s\n", res.c_str());
    return 0;
}
