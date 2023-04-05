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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int> path_vec;
        PathSumAux(root, targetSum, path_vec, 0);
        return result_;
    }
private:
    void PathSumAux(const TreeNode * root, int target, vector<int> & path_vec, int sum)
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum + root->val == target)
            {
                path_vec.push_back(root->val);
                result_.push_back(path_vec);
                path_vec.pop_back();
            }
            return;
        }

        path_vec.push_back(root->val);
        PathSumAux(root->left, target, path_vec, sum + root->val);
        PathSumAux(root->right, target, path_vec, sum + root->val);
        path_vec.pop_back();
        return;
    }

    vector<vector<int>> result_;
};

int main(int argc, char ** argv)
{
    return 0;
}
