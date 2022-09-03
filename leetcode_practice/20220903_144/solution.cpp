#include <stdio.h>
#include <deque>
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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        deque<TreeNode*> node_stack;
        while (root != nullptr || !node_stack.empty())
        {
            result.push_back(root->val);
            if (root->right)
            {
                node_stack.push_back(root->right);
            }
            if (root->left)
            {
                node_stack.push_back(root->left);
            }
            root = nullptr;
            if (!node_stack.empty())
            {
                root = node_stack.back();
                node_stack.pop_back();
            }
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
