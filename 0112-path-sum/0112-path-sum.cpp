/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        bool dfs(TreeNode *root, int target)
        {
            if (!root)
                return 0;

            target -= root->val;

            if (!root->left && !root->right)
            {
                if (target == 0)
                    return 1;

                return 0;
            }

            return dfs(root->left, target) || dfs(root->right, target);
        }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum);
    }
};