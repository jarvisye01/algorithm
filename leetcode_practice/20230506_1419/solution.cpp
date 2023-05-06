#include <stdio.h>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution
{
public:
    // use stack
    int minNumberOfFrogs(string croakOfFrogs)
    {
        if (!CheckValid(croakOfFrogs))
            return -1;
        int min_num = 0;
        stack<int> s;
        for (int i = 0; i < croakOfFrogs.size(); i++)
        {
            if (croakOfFrogs[i] == 'c')
            {
                s.push(croakOfFrogs[i]);
                min_num = std::max(min_num, static_cast<int>(s.size()));
            }
            else if (croakOfFrogs[i] == 'k')
            {
                s.pop();
            }
        }
        return min_num;
    }
private:
    // croak
    bool CheckValid(const string & str)
    {
        vector arr(5, 0);
        auto check = [&arr] () -> bool {
            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i] > arr[i - 1])
                    return false;
            }
            return true;
        };
        for (char ch: str)
        {
            switch (ch)
            {
                case 'c':
                    arr[0]++;
                    break;
                case 'r':
                    arr[1]++;
                    break;
                case 'o':
                    arr[2]++;
                    break;
                case 'a':
                    arr[3]++;
                    break;
                case 'k':
                    arr[4]++;
                    break;
            }
            if (!check())
                return false;
        }
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != arr[0])
                return false;
        }
        return true;
    }
};

int main(int argc, char ** argv)
{
    string croaks("crocakcroraoakk");
    int ret = Solution().minNumberOfFrogs(croaks);
    printf("MinNumberOfFrogs %d\n", ret);
    return 0;
}
