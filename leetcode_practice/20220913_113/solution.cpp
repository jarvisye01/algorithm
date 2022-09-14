#include <stdio.h>
#include <vector>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int> path_vec;
        GetTarget(root, path_vec, 0, targetSum);
        return result_;
    }
private:
    void GetTarget(TreeNode * root, vector<int> & path_vec, int total, int target)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            if (total + root->val == target)
            {
                path_vec.push_back(root->val);
                result_.push_back(path_vec);
                path_vec.pop_back();
            }
            return;
        }
        total += root->val;
        path_vec.push_back(root->val);
        GetTarget(root->left, path_vec, total, target);
        GetTarget(root->right, path_vec, total, target);
        total -= root->val;
        path_vec.pop_back();
        return;
    }
private:
    vector<vector<int>> result_;
};

int main(int argc, char ** argv)
{
    return 0;
}
