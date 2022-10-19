#include <stdio.h>

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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (key == root->val)
        {
            if (root->right)
            {
                TreeNode **min_node = nullptr;
                root->right = DeleteMin(root->right, min_node);
                (*min_node)->left = root->left;
                (*min_node)->right = root->right;
                return *min_node;
            }
            else if (root->left)
            {
                return root->left;
            }
            else
            {
                return nullptr;
            }
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
private:
    TreeNode* DeleteMin(TreeNode * root, TreeNode ** min_node)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->left == nullptr)
        {
            *min_node = root;
            return root->right;
        }
        root->left = DeleteMin(root, min_node);
        return root;
    }
};

int main(int argc, char ** argv)
{
    return 0;
}
