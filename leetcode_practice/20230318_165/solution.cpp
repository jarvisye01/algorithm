#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        auto v1 = Split(version1), v2 = Split(version2);
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] != v2[j])
                return v1[i] > v2[j] ? 1 : -1;
            i++, j++;
        }
        while (i < v1.size())
        {
            if (v1[i++] != 0)
                return 1;
        }
        while (j < v2.size())
        {
            if (v2[j++] != 0)
                return -1;
        }
        return 0;
    }
private:
    int StrToInt(const string & str)
    {
        int num = 0, idx = 0;
        while (idx < str.size() && str[idx] == '0')
        {
            idx++;
        }
        for (; idx < str.size(); idx++)
        {
            int x = static_cast<int>(str[idx] - '0');
            num = num * 10 + x;
        }
        return num;
    }
    vector<int> Split(const string & str)
    {
        vector<int> result;
        int start = 0, end = 0;
        while (end < str.size())
        {
            if (str[end] == '.')
            {
                result.push_back(StrToInt(str.substr(start, end - start)));
                start = end + 1;
            }
            end++;
        }

        if (start < end)
            result.push_back(StrToInt(str.substr(start, end - start)));

        return result;
    }
};

int main(int argc, char ** argv)
{
    string version1("0.1"), version2("1.1");
    printf("Compare Version %d\n", Solution().compareVersion(version1, version2));
    return 0;
}
