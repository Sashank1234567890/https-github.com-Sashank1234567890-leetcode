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
        unordered_map<int, int> mp;
    TreeNode* build(vector<int> &pre, vector<int> &in, int &idx, int l, int r)
    {
        int n = pre.size();
        if (idx == n)
            return NULL;
        int val = pre[idx];
        if (mp.find(val) == mp.end())
            return NULL;

        if (mp[val] > r)
            return NULL;

        idx++;
        TreeNode *root = new TreeNode(val);
        root->left = build(pre, in, idx, l, mp[val] - 1);
        root->right = build(pre, in, idx, mp[val] + 1, r);

        return root;
    }
    TreeNode* buildTree(vector<int> &pre, vector<int> &in)
    {
        int idx = 0;
        mp.clear();
        int i = 0;
        for (int &x: in)
            mp[x] = i++;
        return build(pre, in, idx, 0, pre.size() - 1);
    }
};