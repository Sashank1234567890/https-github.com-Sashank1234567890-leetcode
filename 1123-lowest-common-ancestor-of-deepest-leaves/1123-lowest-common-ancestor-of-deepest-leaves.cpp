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

    vector<TreeNode*> v;

    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b) {
        if(!root || root == a || root == b)
            return root;

        TreeNode* left = lca(root->left, a, b);
        TreeNode* right = lca(root->right, a, b);

        if(left && right)
            return root;

        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return NULL;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            v.clear();

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(!node->left && !node->right)
                    v.push_back(node);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }

        TreeNode* ans = v[0];

        for(int i = 1; i < v.size(); i++) {
            ans = lca(root, ans, v[i]);
        }

        return ans;
    }
};