#include <stdio.h>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr)
            return {};
        vector<vector<int>> result;
        deque<TreeNode*> nodes{root};
        while (nodes.size() > 0)
        {
            int count = nodes.size();
            vector<int> level;
            while (level.size() < count)
            {
                TreeNode* node = nodes.front();
                nodes.pop_front();
                if (node->left != nullptr)
                    nodes.push_back(node->left);
                if (node->right != nullptr)
                    nodes.push_back(node->right);
                level.push_back(node->val);
            }
            result.push_back(std::move(level));
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
