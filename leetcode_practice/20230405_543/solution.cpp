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
    int diameterOfBinaryTree(TreeNode* root)
    {
        diameterOfBinaryTreeAux(root);
        return max_len - 1;
    }
    int diameterOfBinaryTreeAux(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left_len = diameterOfBinaryTreeAux(root->left);
        int right_len = diameterOfBinaryTreeAux(root->right);
        max_len = std::max(max_len, left_len + right_len + 1);
        return std::max(left_len, right_len) + 1;
    }
private:
    int max_len{0};
};

int main(int argc, char ** argv)
{
    return 0;
}
