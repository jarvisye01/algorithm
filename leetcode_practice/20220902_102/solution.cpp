#include <algorithm>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty())
        {
            int queue_size = queue.size();
            vector<int> level_vec;
            for (int i = 0; i < queue_size; i++)
            {
                TreeNode * node = queue.front();
                queue.pop_front();
                level_vec.push_back(node->val);
                if (node->left != nullptr)
                {
                    queue.push_back(node->left);
                }
                if (node->right != nullptr)
                {
                    queue.push_back(node->right);
                }
            }
            result.push_back(std::move(level_vec));
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
