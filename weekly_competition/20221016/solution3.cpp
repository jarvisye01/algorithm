#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool sumOfNumberAndReverse(int num)
    {
        for (int i = 0; i <= num; i++)
        {
            if (i + reverse(i) == num)
            {
                return true;
            }
        }
        return false;
    }
private:
     int reverse(int num)
     {
         int ret = 0;
         while (num > 0)
         {
             ret =  ret * 10 + (num % 10);
             num /= 10;
         }
         return ret;
     }
};

int main(int argc, char ** argv)
{
    return 0;
}
