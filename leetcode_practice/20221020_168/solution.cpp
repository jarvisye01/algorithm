#include <locale>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result;
        while (columnNumber > 0)
        {
            --columnNumber;
            result.push_back(char((columnNumber % 26) + 'A'));
            columnNumber /= 26;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char ** argv)
{
    int num = 701;
    string result = Solution().convertToTitle(num);
    printf("convertToTitle: %s\n", result.c_str());
    return 0;
}
