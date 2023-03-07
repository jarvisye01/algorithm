#include <iterator>
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        if (root == nullptr)
            return {};

        deque<TreeNode*> de_que{root};
        deque<int> output;
        while (!de_que.empty())
        {
            TreeNode * node = de_que.back();
            de_que.pop_back();
            // 将结果转移到另一个地方，并且root是最后一个
            output.push_front(node->val);
            if (node->left != nullptr)
                de_que.push_back(node->left);
            if (node->right != nullptr)
                de_que.push_back(node->right);
        }
        return vector<int>(output.begin(), output.end());
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
