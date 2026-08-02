/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right)
 *        : val(x), left(left), right(right) {}
 *};
 */

class Solution
{
    public:

        int ans;

    pair<int, int> find(TreeNode *root)
    {

        if (!root)
            return {
                INT_MAX,
                INT_MIN
            };

        auto left = find(root->left);
        auto right = find(root->right);

        int subMin = min(left.first, right.first);
        int subMax = max(left.second, right.second);

        if (subMin != INT_MAX)
            ans = max(ans, abs(root->val - subMin));

        if (subMax != INT_MIN)
            ans = max(ans, abs(root->val - subMax));

        int curMin = min(root->val, subMin);
        int curMax = max(root->val, subMax);

        return {
            curMin,
            curMax
        };
    }

    int maxAncestorDiff(TreeNode *root)
    {

        ans = 0;

        find(root);

        return ans;
    }
};