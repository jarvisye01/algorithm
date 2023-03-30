#include <stdio.h>
#include <algorithm>
#include <cmath>

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
    bool isBalanced(TreeNode * root)
    {
        return height(root) >= 0;
    }

    bool isBalanced1(TreeNode * root)
    {
        if (root == nullptr)
            return true;
        if (!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        if (std::abs(MaxDepth(root->left) - MaxDepth(root->right)) > 1)
            return false;
        return true;
    }
private:
    int MaxDepth(TreeNode * root)
    {
        if (root == nullptr)
            return 0;
        int left = MaxDepth(root->left), right = MaxDepth(root->right);
        return std::max(left, right) + 1;
    }

    int height(TreeNode * root)
    {
        if (root == nullptr)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1 || right == -1 || std::abs(left - right) > 1)
            return -1;
        return std::max(left, right) + 1;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
