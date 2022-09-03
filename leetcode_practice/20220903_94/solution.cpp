#include <stdio.h>
#include <deque>
#include <set>
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        deque<TreeNode*> node_queue;
        while (root != nullptr || !node_queue.empty())
        {
            while (root != nullptr)
            {
                node_queue.push_back(root);
                root = root->left;
            }
            root = node_queue.back();
            node_queue.pop_back();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
