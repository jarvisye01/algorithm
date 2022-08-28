#include <stddef.h>
#include <stdio.h>
#include <deque>
#include <string>

using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        deque<char> oDeque;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                if (!oDeque.empty())
                {
                    oDeque.pop_back();
                }
            }
            else
            {
                oDeque.push_back(s[i]);
            }
        }

        string sResult(oDeque.size(), 0);
        string::size_type iIdx = 0;
        for (auto iter = oDeque.begin(); iter != oDeque.end(); iter++)
        {
            sResult[iIdx++] = *iter;
        }
        return sResult;
    }
};

int main(int argc, char ** argv)
{
    string sStr("leet**cod*e");
    string sResult = Solution().removeStars(sStr);
    printf("origin: %s\n", sStr.c_str());
    printf("origin: %s\n", sResult.c_str());
    return 0;
}
