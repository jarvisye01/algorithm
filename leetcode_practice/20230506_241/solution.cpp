#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        return Compute(expression);
    }
private:
    vector<int> Compute(const string & expression)
    {
        if (AllNumber(expression))
            return {std::stoi(expression)};

        vector<int> result;
        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*')
            {
                vector<int> left = Compute(expression.substr(0, i));
                vector<int> right = Compute(expression.substr(i + 1));
                Calculate(expression[i], left, right, result);
            }
        }

        return result;
    }

    bool AllNumber(const string & expression)
    {
        for (char ch: expression)
        {
            if (ch == '-' || ch == '+' || ch == '*')
                return false;
        }
        return true;
    }

    void Calculate(char op, const vector<int> & left, const vector<int> & right, vector<int> & result)
    {
        for (int x: left)
        {
            for (int y: right)
            {
                switch (op)
                {
                    case '-':
                        result.push_back(x - y);
                        break;
                    case '+':
                        result.push_back(x + y);
                        break;
                    case '*':
                        result.push_back(x * y);
                        break;
                }
            }
        }
        return;
    }
};

int main(int argc, char ** argv)
{
    string expression("2*3-4*5");
    vector<int> result = Solution().diffWaysToCompute(expression);
    printf("Result: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
