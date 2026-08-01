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

    int nextLeaf(stack<TreeNode*>& st) {

        while (!st.empty()) {

            TreeNode* curr = st.top();
            st.pop();

            if (!curr->left && !curr->right)
                return curr->val;

            if (curr->right)
                st.push(curr->right);

            if (curr->left)
                st.push(curr->left);
        }

        return -1;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        stack<TreeNode*> st1, st2;

        if (root1)
            st1.push(root1);

        if (root2)
            st2.push(root2);

        while (!st1.empty() && !st2.empty()) {

            int leaf1 = nextLeaf(st1);
            int leaf2 = nextLeaf(st2);

            if (leaf1 != leaf2)
                return false;
        }

        return st1.empty() && st2.empty();
    }
};