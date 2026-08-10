class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, int temp) {
        if(root != NULL) {
            
            temp = temp ^ (1 << root->val);
            
            if(root->left == NULL && root->right == NULL) {
                if((temp & (temp - 1)) == 0) { 
                    result++;
                }
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);


        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {

        solve(root, 0);
        return result;
    }
};
