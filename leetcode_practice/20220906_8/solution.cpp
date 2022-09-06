#include <cstdint>
#include <stdio.h>
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int ret = 0;
        bool b_negative = false;

        int step = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (step == 0 && s[i] == ' ')
            {
                continue;
            }

            step = step == 0 ? 1 : step;
            if (step == 1 && (s[i] == '+' || s[i] == '-'))
            {
                if (s[i] == '-')
                {
                    b_negative = true;
                }
                step = 2;
                continue;
            }

            step = step == 1 ? 2 : step;
            if (step == 2 && (s[i] < '0' || s[i] > '9'))
            {
                break;
            }

            int num = s[i] - '0';
            if (ret > (INT32_MAX - num) / 10)
            {
                ret = b_negative ? INT32_MIN : INT32_MAX;
                b_negative = false;
                break;
            }
            ret = ret * 10 + num;
        }

        return b_negative ? -1 * ret : ret;
    }
};

int main(int argc, char ** argv)
{
    string s("+-12");
    int num = Solution().myAtoi(s);
    printf("num %d\n", num);
    return 0;
}
