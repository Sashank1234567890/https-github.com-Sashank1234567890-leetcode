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
    string str(TreeNode* root){
    if(!root){
        return "";
    }
    string left=str(root->left);
    string right=str(root->right);
    string ans='('+to_string(root->val);
    if(left.size()>0){
          cout<<left<<endl;
          ans+=left;
    }
    if(right.size()>0){
           cout<<right<<endl;
           if(left.size()==0){
            ans+="()";
           }
          ans+=right;
    }
    ans+=')';
    return ans;
    }
    string tree2str(TreeNode* root) {
    if(!root){
        return "";
    }
    string s=str(root);
    s.pop_back();
    return s.substr(1);
    }
};