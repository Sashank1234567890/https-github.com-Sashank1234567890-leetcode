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
    pair<int,int> dfs(TreeNode* root,int &cnt){
        if(!root){
            return {0,0};
        }
        if(!root->left&&!root->right){
        cnt++;
        return {root->val,1};
        }
        auto [lsum,lcnt]=dfs(root->left,cnt);
        auto [rsum,rcnt]=dfs(root->right,cnt);

        if((root->val+lsum+rsum)/(1+lcnt+rcnt) ==root->val)
        cnt++;

        return {root->val+lsum+rsum,1+lcnt+rcnt};

    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)
           return 0;
        int cnt=0;
        dfs(root,cnt);
        return cnt;
    }
};