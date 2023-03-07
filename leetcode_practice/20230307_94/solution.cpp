#include <stdio.h>
#include <deque>
#include <vector>

using std::deque;
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        deque<TreeNode*> queue;
        while (root != nullptr || !queue.empty())
        {
            while (root != nullptr)
            {
                queue.push_back(root);
                root = root->left;
            }
            // at most left node
            TreeNode * node = queue.back();
            queue.pop_back();
            result.push_back(node->val);
            root = node->right;
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
