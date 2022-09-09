#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // reverse all string
        std::reverse(s.begin(), s.end());
        int idx = 0, len = 0;;
        // remove space
        for (int i = 0; i < s.size(); i++)
        {
            // head space and tail space
            if (s[i] == ' ' && (idx == 0 || s[idx - 1] == ' '))
            {
                continue;
            }
            s[idx++] = s[i];
            len++;
        }
        while (len > 0 && s[len - 1] == ' ')
        {
            len--;
        }
        // reverse every word
        for (int i = 0; i < len + 1; i++)
        {
            int start = i;
            while (i < len && s[i] != ' ')
            {
                i++;
            }
            std::reverse(s.begin() + start, s.begin() + i);
        }
        return s.substr(0, len);
    }
};

int main(int argc, char ** argv)
{
    string str("the sky is blue");
    string res = Solution().reverseWords(str);
    printf("res \"%s\"\n", res.c_str());
    return 0;
}
