#include <stdio.h>
#include <algorithm>
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        deque<TreeNode*> node_stack;

        while (root != nullptr || !node_stack.empty())
        {
            if (root != nullptr)
            {
                result.push_back(root->val);
                if (root->left != nullptr)
                {
                    node_stack.push_back(root->left);
                }
                if (root->right != nullptr)
                {
                    node_stack.push_back(root->right);
                }
            }
            root = nullptr;
            if (!node_stack.empty())
            {
                root = node_stack.back();
                node_stack.pop_back();
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
