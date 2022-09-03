#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const char ZERO = '0';

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1;
        string result;
        int c = 0;
        while (i >= 0 || j >= 0)
        {
            int a = 0, b = 0;
            if (i >= 0)
            {
                a = num1[i] - ZERO;
                i--;
            }
            if (j >= 0)
            {
                b = num2[j] - ZERO;
                j--;
            }
            int sum = a + b + c;
            result.push_back(ZERO + (sum % 10));
            c = sum / 10;
        }
        if (c > 0)
        {
            result.push_back(ZERO + c);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char ** argv)
{
    string s1("123");
    string s2("789");
    string sum = Solution().addStrings(s1, s2);
    printf("sum %s\n", sum.c_str());
    return 0;
}
