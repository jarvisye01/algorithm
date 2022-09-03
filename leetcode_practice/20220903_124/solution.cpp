#include <stdio.h>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int GetMaxPath(TreeNode * root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left_max = GetMaxPath(root->left);
        int right_max = GetMaxPath(root->right);
        int max_result = root->val, result = root->val;
        int max = std::max(left_max, right_max);
        if (left_max > 0)
        {
            max_result += left_max;
        }
        if (right_max > 0)
        {
            max_result += right_max;
        }
        max_path_ = std::max(max_path_, max_result);
        result += max > 0 ? max : 0;
        return result;
    }
    int maxPathSum(TreeNode* root)
    {
        max_path_ = 0;
        GetMaxPath(root);
        return max_path_;
    }
private:
    int max_path_;
};

int main(int argc, char ** argv)
{
    return 0;
}
