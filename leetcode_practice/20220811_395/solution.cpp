#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int iRet = 0;
        map<char, int> oMap;
        for (int i = 0; i < s.size(); i++)
        {
            oMap[s[i]]++;
        }

        int iIdx = 0;
        while (iIdx < s.size())
        {
            while (iIdx < s.size() && oMap[s[iIdx]] < k)
            {
                iIdx++;
            }

            if (iIdx >= s.size())
            {
                break;
            }

            int iStart = iIdx;
            map<char, int> oTmpMap;
            while (iIdx < s.size() && oMap[s[iIdx]] >= k)
            {
                oTmpMap[s[iIdx]]++;
                iIdx++;
            }
            bool bValid = false, bAllValid = true;
            for (const auto oIter: oTmpMap)
            {
                if (oIter.second >= k)
                {
                    bValid = true;
                }
                else
                {
                    bAllValid = false;
                }
            }
            if (bValid)
            {
                if (bAllValid)
                {
                    iRet = std::max(iRet, iIdx - iStart);
                }
                else
                {
                    iRet = std::max(iRet, longestSubstring(s.substr(iStart, iIdx - iStart), k));
                }
            }
        }
        return iRet;
    }
};

int main(int argc, char ** argv)
{
    string sStr("bbaaacb");
    int iRet = Solution().longestSubstring(sStr, 3);
    printf("iRet %d\n", iRet);
    return 0;
}
