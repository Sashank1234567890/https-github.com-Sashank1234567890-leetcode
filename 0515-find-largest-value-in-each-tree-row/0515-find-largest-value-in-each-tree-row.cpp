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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
        return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        
        while(!q.empty()){
            int sz=q.size();
            long long  mx=LLONG_MIN;
            while(sz--){
                TreeNode* node=q.front();
                q.pop();
                mx=max(mx,1LL*node->val);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            if(mx!=LLONG_MIN)
            ans.push_back(mx);
        }
    return ans;}
};
