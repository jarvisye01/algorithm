#include <stdio.h>
#include <map>

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
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return isValidBST(root->left) && isValidBST(root->right) &&
            (!root->left || GetMax(root->left) < root->val) &&
            (!root->right || root->val < GetMin(root->right));
    }
private:
    int GetMin(TreeNode * root)
    {
        if (min_map.find(root) != min_map.end())
        {
            return min_map.find(root)->second;
        }
        int min_val = root->val;
        if (root->left)
        {
            min_val = std::min(min_val, GetMin(root->left));
        }
        if (root->right)
        {
            min_val = std::min(min_val, GetMin(root->right));
        }
        min_map[root] = min_val;
        return min_val;
    }

    int GetMax(TreeNode * root)
    {
        if (max_map.find(root) != max_map.end())
        {
            return max_map.find(root)->second;
        }
        int max_val = root->val;
        if (root->left)
        {
            max_val = std::max(max_val, GetMax(root->left));
        }
        if (root->right)
        {
            max_val = std::max(max_val, GetMax(root->right));
        }
        max_map[root] = max_val;
        return max_val;
    }
private:
    map<TreeNode*, int> min_map;
    map<TreeNode*, int> max_map;
};

int main(int argc, char ** argv)
{
    return 0;
}
