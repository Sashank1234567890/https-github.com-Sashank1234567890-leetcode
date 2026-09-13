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

    void str(TreeNode* root, string &ans) {

        if (!root){
            ans+="()";
            return ;
        }

        ans += "(";
        ans += to_string(root->val);

        if (root->left || root->right) {
            str(root->left, ans);
        }

        if (root->right) {
            str(root->right, ans);
        }

        ans += ")";
    }

    string tree2str(TreeNode* root) {

        string ans;

        str(root, ans);

        return ans.substr(1, ans.size() - 2);
    }
};