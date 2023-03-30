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
    int sumNumbers(TreeNode* root)
    {
        int sum = 0;
        Sum(root, 0, sum);
        return sum;
    }
private:
    void Sum(const TreeNode * root, int num, int & sum)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            sum += num * 10 + root->val;
            return;
        }
        int new_num = num * 10 + root->val;
        Sum(root->left, new_num, sum);
        Sum(root->right, new_num, sum);
        return;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
