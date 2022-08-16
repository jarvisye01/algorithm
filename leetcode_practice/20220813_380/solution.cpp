#include <array>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <vector>

using namespace std;

/*
 * 本题的要点是如何通过数组完成O(1)的插入和删除操作
 */
class RandomizedSet
{
public:
    RandomizedSet()
    {
        srand(time(nullptr));
    }
    
    bool insert(int val)
    {
        if (m_oMap.find(val) != m_oMap.end())
        {
            return false;
        }
        m_oNumVec.push_back(val);
        m_oMap[val] = m_oNumVec.size() - 1;
        return true;
    }
    
    bool remove(int val)
    {
        if (m_oMap.find(val) == m_oMap.end())
        {
            return false;
        }
        int iIdx = m_oMap[val];
        std::swap(m_oNumVec[iIdx], m_oNumVec[m_oNumVec.size() - 1]);
        m_oMap[m_oNumVec[iIdx]] = iIdx;
        m_oMap.erase(m_oMap.find(val));
        m_oNumVec.pop_back();
        return true;
    }
    
    int getRandom()
    {
        return m_oNumVec[rand() % m_oNumVec.size()];
    }
private:
    vector<int> m_oNumVec;
    map<int, int> m_oMap;
};

int main(int argc, char ** argv)
{
    RandomizedSet rSet;
    rSet.insert(1);
    rSet.remove(2);
    rSet.insert(2);
    printf("random: %d\n", rSet.getRandom());
    rSet.remove(1);
    rSet.insert(2);
    printf("random: %d\n", rSet.getRandom());
    return 0;
}
