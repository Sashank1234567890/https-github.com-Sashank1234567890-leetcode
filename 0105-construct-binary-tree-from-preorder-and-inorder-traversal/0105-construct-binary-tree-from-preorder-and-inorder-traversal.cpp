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
        TreeNode* build(vector<int> &pre, vector<int> &in, int &idx, int l, int r)
        {
            int n = pre.size();
            if (idx == n)
                return NULL;
            int val = pre[idx];
            int i = -1, j = 0;
            while (j <= r)
            {
                if (val == in[j])
                {
                    i = j;
                    break;
                }
                j++;
            }
            if (i == -1)
                return NULL;
            idx++;
            TreeNode *root = new TreeNode(val);
            root->left = build(pre, in, idx, l, i - 1);
            root->right = build(pre, in, idx, i + 1, r);

            return root;
        }
    TreeNode* buildTree(vector<int> &pre, vector<int> &in)
    {
        int idx = 0;
        return build(pre, in, idx, 0, pre.size() - 1);
    }
};