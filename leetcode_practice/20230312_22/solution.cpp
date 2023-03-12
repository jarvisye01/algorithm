#include <stdio.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n <= 0)
            return result_;
        gen("", n, n);
        return result_;
    }
private:
    void gen(string s, int rest_left, int rest_right)
    {
        if (rest_left == 0 && rest_right == 0)
        {
            result_.push_back(s);
            return;
        }
        if (rest_left == rest_right)
        {
            gen(s + "(", rest_left - 1, rest_right);
        }
        else
        {
            if (rest_left > 0)
                gen(s + "(", rest_left - 1, rest_right);
            gen(s + ")", rest_left, rest_right - 1);
        }
        return;
    }

    vector<string> result_;
};

int main(int argc, char ** argv)
{
    auto result = Solution().generateParenthesis(4);
    printf("Vector: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%s ", result[i].c_str());
    }
    printf("\n");
    return 0;
}
