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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        vector<int> path_vec;
        return GetTarget(root, path_vec, 0, targetSum);
    }
private:
    bool GetTarget(TreeNode * root, vector<int> & path_vec, int total, int target)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            if (total + root->val == target)
            {
                path_vec.push_back(root->val);
                path_vec.pop_back();
                return true;
            }
            return false;
        }
        total += root->val;
        path_vec.push_back(root->val);
        bool b1 = GetTarget(root->left, path_vec, total, target);
        bool b2 = GetTarget(root->right, path_vec, total, target);
        total -= root->val;
        path_vec.pop_back();
        return b1 || b2;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
