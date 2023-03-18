#include <stdio.h>
#include <algorithm>
#include <string>

using std::string;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1.front() == '0' || num2.front() == '0')
            return "0";

        string result("0");
        string base;
        for (int i = num2.size() - 1; i >= 0; i--)
        {
            string tmp = Multiply(num1, num2[i]) + base;
            result = Add(result, tmp);
            base.push_back('0');
        }
        return result;
    }
private:
    string Multiply(const string & num, char ch)
    {
        if (ch == '0')
            return "0";
        string result;
        int tmp = 0, n = ch - '0';
        for (int i = num.size() - 1; i >= 0; i--)
        {
            int m = static_cast<int>(num[i] - '0');
            result.push_back(static_cast<char>((m * n + tmp) % 10 + '0'));
            tmp = (m * n + tmp) / 10;
        }
        if (tmp > 0)
            result.push_back(static_cast<char>(tmp + '0'));
        std::reverse(result.begin(), result.end());
        return result;
    }
    string Add(const string & num1, const string & num2)
    {
        constexpr char ZERO = '0';
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
    string num1("123"), num2("456");
    printf("Multiply %s\n", Solution().multiply(num1, num2).c_str());
    return 0;
}
