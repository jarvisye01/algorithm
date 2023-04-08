#include <cstddef>
#include <stdio.h>
#include <vector>

using std::vector;

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
    bool hasPathSum(TreeNode * root, int targetSum)
    {
        return HasPathSumAux(root, targetSum, 0);
    }
private:
    bool HasPathSumAux(const TreeNode * root, int target, int path_sum)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
        {
            return path_sum + root->val == target;
        }

        if (HasPathSumAux(root->left, target, path_sum + root->val) ||
                HasPathSumAux(root->right, target, path_sum + root->val))
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
