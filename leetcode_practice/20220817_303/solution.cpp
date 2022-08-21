#include <stdio.h>
#include <vector>

using namespace std;

class NumArray
{
public:
    NumArray(vector<int>& nums)
    {
        m_oNumVec.resize(nums.size(), 0);
        int iSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            iSum += nums[i];
            m_oNumVec[i] = iSum;
        }
    }

    int sumRange(int left, int right)
    {
        int iPreNum = 0;
        if (left > 0)
        {
            iPreNum = m_oNumVec[left - 1];
        }
        return m_oNumVec[right] - iPreNum;
    }
private:
    vector<int> m_oNumVec;
};

int main(int argc, char ** argv)
{
    return 0;
}
