#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    // 会有溢出问题
    // 如果num % m == 0，那么(num * 10) % m == 0一定成立，只需要判断后续的即可
    vector<int> divisibilityArray1(string word, int m)
    {
        int len = word.size();
        vector<int> result(len, 0);
        int num = 0;
        for (int i = 0; i < len; i++)
        {
            num = num * 10 + static_cast<int>(word[i] - '0');
            if (num % m == 0)
            {
                num = 0;
                result[i] = 1;
            }
        }
        return result;
    }

    vector<int> divisibilityArray(string word, int m)
    {
        int len = word.size();
        vector<int> result(len, 0);
        unsigned long long num = 0;
        for (int i = 0; i < len; i++)
        {
            num = (num * 10 + static_cast<unsigned long long>(word[i] - '0')) % m;
            if (num == 0)
            {
                result[i] = 1;
            }
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    string word("998244353");
    int m = 3;
    vector<int> result = Solution().divisibilityArray(word, m);
    printf("Vector: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
