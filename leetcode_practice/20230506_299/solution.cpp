#include <stdio.h>
#include <map>
#include <string>

using std::map;
using std::string;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        map<char, int> m1, m2;
        int len = secret.size();
        int bull_count = 0;
        for (int i = 0; i < len; i++)
        {
            if (secret[i] == guess[i])
            {
                bull_count++;
            }
            else
            {
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }
        int cow_count = 0;
        for (const auto & iter: m2)
        {
            if (m1.find(iter.first) == m1.end())
                continue;
            cow_count += std::min(iter.second, m1.find(iter.first)->second);
        }
        return std::to_string(bull_count) + "A" + std::to_string(cow_count) + "B";
    }
};

int main(int argc, char ** argv)
{
    string secret("1123"), guess("0111");
    string ret = Solution().getHint(secret, guess);
    printf("GetHint %s\n", ret.c_str());
    return 0;
}
