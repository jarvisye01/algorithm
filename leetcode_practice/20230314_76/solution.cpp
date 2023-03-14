#include <set>
#include <stdio.h>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::set;
using std::string;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // init hash and set for string t
        unordered_map<char, int> char_hash, tmp_hash;
        set<char> char_set, tmp_set;
        for (char ch: t)
        {
            char_set.insert(ch);
            char_hash[ch]++;
        }
        int start = 0, end = 0;
        string result;
        for (; end < s.size(); end++)
        {
            char c = s[end];
            if (char_set.find(c) == char_set.end())
                continue;

            // tmp_hash中的字符c数量加一
            tmp_hash[c]++;
            if (tmp_hash[c] >= char_hash[c])
                tmp_set.insert(c);  // tmp_set表示数量已经满足的字符
            if (tmp_set.size() == char_set.size())
            {
                for (; start <= end; start++)
                {
                    if (char_set.find(s[start]) == char_set.end())
                        continue;
                    if (tmp_hash[s[start]] > char_hash[s[start]])
                        tmp_hash[s[start]]--;
                    else
                        break; // 如果再循环就不满足了
                }
                if (result.size() == 0 || (end - start + 1) < result.size())
                    result = s.substr(start, end - start + 1);
                // 让条件再次不满足
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
    string t("ABC");
    string s("ADOBECODEBANC");
    string result = Solution().minWindow(s, t);
    printf("result %s\n", result.c_str());
    return 0;
}
