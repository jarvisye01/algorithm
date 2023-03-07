#include <stdio.h>
#include <algorithm>

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
    int maxPathSum(TreeNode * root)
    {
        max_path_ = -1001;
        GetMaxPath(root);
        return max_path_;
    }
private:
    // 1.找出包含root节点的最大路径和，并且最多只能包含一个子节点；
    // 2.此时是必要计算左子节点和右子节点的最大路径和，正好可以更新题目中所求的最大路径和；
    int GetMaxPath(TreeNode * root)
    {
        if (root == nullptr)
            return 0;
        int left_max = GetMaxPath(root->left);
        int right_max = GetMaxPath(root->right);
        int max_result = root->val, result = root->val;
        if (left_max > 0)
            max_result += left_max;
        if (right_max > 0)
            max_result += right_max;
        int max = std::max(left_max, right_max);
        // 最大路径和必然只能加上最大的
        result += max > 0 ? max : 0;
        max_path_ = std::max(max_result, max_path_);
        return result;
    }

    int max_path_;
};

int main(int argc, char ** argv)
{
    return 0;
}
