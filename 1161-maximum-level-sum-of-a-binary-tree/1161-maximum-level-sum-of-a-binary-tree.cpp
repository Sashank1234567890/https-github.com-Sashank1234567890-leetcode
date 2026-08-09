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
    int maxLevelSum(TreeNode* root) {
        int l=1,level=1;
        queue<TreeNode*>q;
        q.push(root);
        long long  ans=LLONG_MIN;
        
        while(!q.empty()){
            int sz=q.size();
            long long sum=0;
            while(sz--){
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            if(sum>ans){
                ans=sum;
                l=level;
            }
            level++;
        }
    return l;}
};