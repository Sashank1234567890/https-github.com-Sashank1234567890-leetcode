/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, string path, string &ans) {
        if (!root)
            return;

        path.push_back('a' + root->val);

        if (!root->left && !root->right) {
            reverse(path.begin(), path.end());

            if (ans == "" || path < ans)
                ans = path;

            return;
        }

        solve(root->left, path, ans);
        solve(root->right, path, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string path = "";

        solve(root, path, ans);

        return ans;
    }
};