#include <stdio.h>

#include <algorithm>

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
    int diameterOfBinaryTree(TreeNode* root)
    {
        diamater_ = 0;
        GetDepth(root);
        return diamater_;
    }
private:
    int GetDepth(TreeNode * root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int d1 = GetDepth(root->left);
        int d2 = GetDepth(root->right);
        diamater_ = std::max(diamater_, d1 + d2 - 1);
        return std::max(d1, d2) + 1;
    }
private:
    int diamater_;
};

int main(int argc, char ** argv)
{
    return 0;
}
