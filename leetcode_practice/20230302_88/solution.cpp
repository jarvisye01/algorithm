#include <stdio.h>
#include <vector>

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int idx = m + n - 1;
        for (; idx >= 0; idx--)
        {
            if (m > 0 && n > 0)
            {
                if (nums1[m - 1] > nums2[n - 1])
                {
                    nums1[idx] = nums1[m - 1];
                    m--;
                }
                else
                {
                    nums1[idx] = nums2[n - 1];
                    n--;
                }
            }
            else if (n > 0)
            {
                nums1[idx] = nums2[n - 1];
                n--;
            }
            else
            {
                break;
            }
        }
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
