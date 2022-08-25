#include <stdio.h>
#include <vector>

using namespace std;

/*
 * key: 除了暴力法，这个题目考察的是经典的埃筛法；
 */
class Solution
{
public:
    bool isPrime(int N)
    {
        if (N <= 1)
        {
            return false;
        }
        // i * i <= N 可以用这个小技巧来减少循环
        for (int i = 2; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int countPrime(int N)
    {
        vector<bool> oPrimeVec(N + 1, true);
        for (int i = 2; i <=N; i++)
        {
            if (!oPrimeVec[i])
            {
                continue;
            }
            if (isPrime(i))
            {
                for (int k = i + 1; k <= N; k++)
                {
                    if (oPrimeVec[k] && k % i == 0)
                    {
                        oPrimeVec[k] = false;;
                    }
                }
            }
            else
            {
                oPrimeVec[i] = false;
            }
        }
        int iCount = 0;
        for (int i = 2; i <= N; i++)
        {
            iCount += oPrimeVec[i] ? 1 : 0;
        }
        return iCount;
    }
};

int main(int argc, char ** argv)
{
    int iCount = Solution().countPrime(100);
    printf("iCount %d\n", iCount);
    return 0;
}
