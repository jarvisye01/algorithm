#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int calTime(vector<string> & garbage, vector<int> & travel, char cType, int iPos)
    {
        int iTotal = 0;
        for (int i = 0; i <= iPos; i++)
        {
            if (i > 0)
            {
                iTotal += travel[i - 1];
            }
            int iTmp = std::count(garbage[i].begin(), garbage[i].end(), cType);
            iTotal += iTmp;
        }
        return iTotal;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        int iTotal = 0;
        vector<int> oPosInfo(3, 0);
        for (int i = 0; i < garbage.size(); i++)
        {
            if (garbage[i].find('M') != string::npos)
            {
                oPosInfo[0] = i;
            }
            if (garbage[i].find('P') != string::npos)
            {
                oPosInfo[1] = i;
            }
            if (garbage[i].find('G') != string::npos)
            {
                oPosInfo[2] = i;
            }
        }
        iTotal += calTime(garbage, travel, 'M', oPosInfo[0]);
        iTotal += calTime(garbage, travel, 'P', oPosInfo[1]);
        iTotal += calTime(garbage, travel, 'G', oPosInfo[2]);
        return iTotal;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
