#include <stdio.h>
#include <algorithm>

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        int left = 1, right = (x / 2) + 1;
        while (left < right)
        {
            // 使用long long防止乘法溢出
            long long mid = left + (right - left) / 2;
            if (mid * mid == x || (mid * mid < x && (mid + 1) * (mid + 1) > x))
                return mid;
            else if (mid * mid < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    // newton
    int sqrt(int x)
    {
        if (x <= 1)
            return x;
        double C = x, x0 = C;
        while (true)
        {
            double xi = 0.5 * (x0 + C / x0);
            if (std::abs(x0 - xi) < 1e-7)
                break;
            x0 = xi;
        }
        return int(x0);
    }
};

int main(int argc, char ** argv)
{
    for (int i = 0; i < 100; i++)
    {
        printf("sqrt(%d) = %d\n", i, Solution().mySqrt(i));
    }
    return 0;
}
