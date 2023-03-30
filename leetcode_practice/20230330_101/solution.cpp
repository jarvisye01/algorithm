#include <cstddef>
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
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        return IsSymm(root->left, root->right);
    }
private:
    bool IsSymm(const TreeNode * root1, const TreeNode * root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr)
            return false;

        if (root1->val != root2->val)
            return false;

        return IsSymm(root1->left, root2->right) && IsSymm(root1->right, root2->left);
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
