#include <stdio.h>

/*
 * key: 二分法和牛顿迭代法；
 */
class Solution
{
public:
    int mySqrt(int x)
    {
        int iLeft = 1, iRight = x;
        while (iLeft <= iRight)
        {
            int iMid = iLeft + (iRight - iLeft) / 2;
            // 采用二分法迭代，需要注意有可能会有溢出
            if ((iMid == x / iMid) && (x % iMid == 0))
            {
                return iMid;
            }
            else if (iMid > x / iMid)
            {
                iRight = iMid - 1;
            }
            else
            {
                iLeft = iMid + 1;
            }
        }
        return iRight;
    }
};

int main(int argc, char ** argv)
{
    int iRet = Solution().mySqrt(8);
    printf("iRet %d\n", iRet);
    return 0;
}
