#include <stdio.h>
#include <queue>
#include <string>

using std::deque;
using std::string;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() == 0)
            return true;

        deque<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stack.push_back(s[i]);
            }
            else
            {
                if (stack.size() == 0)
                    return false;
                char a = s[i], b = stack.back();
                if ((a == ')' && b != '(') || (a == ']' && b != '[') || (a == '}' && b != '{'))
                    return false;
                stack.pop_back();
            }
        }
        return stack.size() == 0;
    }
};

int main(int argc, char ** argv)
{
    string str("()[]{}");
    bool valid = Solution().isValid(str);
    printf("valid %d\n", valid ? 1 : 0);
    return 0;
}
