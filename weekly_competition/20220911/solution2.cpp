#include <stdio.h>
#include <set>
#include <string>

using namespace std;

class Solution
{
public:
    int partitionString(string s)
    {
        int start = 0, end = 0, count = 0;
        set<char> char_set;
        for (; end < s.size(); end++)
        {
            if (char_set.find(s[end]) == char_set.end())
            {
                char_set.insert(s[end]);
                continue;
            }
            count++;
            start = end;
            char_set.clear();
            if (end < s.size())
            {
                char_set.insert(s[end]);
            }
        }
        if (end > 0)
        {
            count++;
        }
        return count;
    }
};

int main(int argc, char ** argv)
{
    string str("abacaba");
    int count = Solution().partitionString(str);
    printf("count: %d\n", count);
    return 0;
}
