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
    int SumNode(TreeNode* root,bool isLeft){
        if(!root)
        return 0;
        if(!root->left&&!root->right){
            return isLeft==1?root->val:0;
        }

        int lsum=SumNode(root->left,1);
        int rsum=SumNode(root->right,0);

        return lsum+rsum;

    }
    int sumOfLeftLeaves(TreeNode* root) {
        return SumNode(root,0);
    }
};