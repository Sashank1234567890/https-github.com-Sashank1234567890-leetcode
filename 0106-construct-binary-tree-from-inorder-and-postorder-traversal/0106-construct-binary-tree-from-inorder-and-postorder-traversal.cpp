/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        unordered_map<int, int> mp;
    int idx;

    TreeNode* build(vector<int> &inorder, vector<int> &postorder,
        int l, int r)
    {

        if (l > r)
            return NULL;

        TreeNode *root = new TreeNode(postorder[idx--]);

        int pos = mp[root->val];

        root->right = build(inorder, postorder, pos + 1, r);
        root->left = build(inorder, postorder, l, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = inorder.size();

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        idx = n - 1;

        return build(inorder, postorder, 0, n - 1);
    }
};