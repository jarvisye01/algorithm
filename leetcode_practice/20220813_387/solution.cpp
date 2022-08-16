#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
#if 0
    int firstUniqChar(string s)
    {
        map<char, int> oMap;
        for (char ch: s)
        {
            oMap[ch]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (oMap[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
#endif
    int firstUniqChar(string s)
    {
        int oArray[26] = {0};
        for (char ch: s)
        {
            oArray[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (oArray[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char ** argv)
{
    string sStr("hhlello");
    int iRet = Solution().firstUniqChar(sStr);
    printf("iRet: %d\n", iRet);
    return 0;
}
