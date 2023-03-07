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
        if (root == nullptr)
            return result;
        deque<TreeNode*> de_que{root};
        while (!de_que.empty())
        {
            TreeNode * node = de_que.back();
            // 先输出即可
            result.push_back(node->val);
            de_que.pop_back();
            if (node->right != nullptr)
                de_que.push_back(node->right);
            if (node->left != nullptr)
                de_que.push_back(node->left);
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
