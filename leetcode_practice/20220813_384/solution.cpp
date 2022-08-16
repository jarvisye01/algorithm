#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class Solution
{
public:
    Solution(vector<int>& nums): m_oNumVec(nums)
    {
        srand(time(nullptr));
    }
    
    vector<int> reset()
    {
        return m_oNumVec;
    }
    
    vector<int> shuffle()
    {
        vector<int> oNumVec(m_oNumVec.begin(), m_oNumVec.end());
        for (int i = 0; i < oNumVec.size(); i++)
        {
            std::swap(oNumVec[i], oNumVec[i + rand() % (oNumVec.size() - i)]);
        }
        return oNumVec;
    }

private:
    vector<int> m_oNumVec;
};

int main(int argc, char ** argv)
{
    return 0;
}
