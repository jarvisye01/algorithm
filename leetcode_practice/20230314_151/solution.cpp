#include <stdio.h>
#include <string>

using std::string;

class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == ' ')
            {
                i++;
                continue;
            }
            int start = i;
            while (i < s.size() && s[i] != ' ')
            {
                i++;
            }
            if (result.size() == 0)
                result = s.substr(start, i - start);
            else
                result = s.substr(start, i - start) + " " + result;
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    string str("  the sky is   blue   ");
    string result = Solution().reverseWords(str);
    printf("result %s\n", result.c_str());
    return 0;
}
