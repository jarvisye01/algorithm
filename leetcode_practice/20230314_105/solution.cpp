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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    // 记住构建的范围preorder[a, b]和inorder[c, d]就可以了;
    TreeNode* build(const vector<int> & preorder, const vector<int> & inorder,
            int a, int b, int c, int d)
    {
        if (a > b)
            return nullptr;
        if (a == b)
            return new TreeNode(preorder[a]);
        TreeNode * root = new TreeNode(preorder[a]);
        TreeNode *left = nullptr, *right = nullptr;
        int root_idx = -1;
        for (int i = c; i <= d; i++)
        {
            if (inorder[i] == preorder[a])
            {
                root_idx = i;
                break;
            }
        }
        left = build(preorder, inorder, a + 1, a + root_idx - c, b, root_idx - 1);
        right = build(preorder, inorder, a + root_idx - c + 1, b, root_idx + 1, d);
        root->left = left, root->right = right;
        return root;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
