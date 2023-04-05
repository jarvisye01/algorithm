#include <stdio.h>
#include <vector>

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
    bool isValidBST(TreeNode * root)
    {
        vector<int> vec;
        DFS(root, vec);
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] <= vec[i - 1])
                return false;
        }
        return true;
    }
private:
    void DFS(const TreeNode * root, vector<int> & vec)
    {
        if (root == nullptr)
            return;

        DFS(root->left, vec);
        vec.push_back(root->val);
        DFS(root->right, vec);
        return;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
