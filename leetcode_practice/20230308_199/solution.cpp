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
    vector<int> rightSideView(TreeNode * root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;
        deque<TreeNode*> q{root};
        while (!q.empty())
        {
            int sz = q.size();
            result.push_back(q.back()->val);
            for (int i = 0; i < sz; i++)
            {
                TreeNode * node = q.front();
                q.pop_front();
                if (node->left != nullptr)
                    q.push_back(node->left);
                if (node->right != nullptr)
                    q.push_back(node->right);
            }
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
