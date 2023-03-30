#include <stdio.h>

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
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left = maxDepth(root->left), right = maxDepth(root->right);
        return std::max(left, right) + 1;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
