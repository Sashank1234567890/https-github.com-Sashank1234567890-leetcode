class Solution {
public:

    void morris(TreeNode* root, vector<int>& leaf) {

        TreeNode* curr = root;

        while (curr) {

            if (!curr->left) {

                if (!curr->left && !curr->right)
                    leaf.push_back(curr->val);

                curr = curr->right;
            }
            else {

                TreeNode* pred = curr->left;

                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {

                    pred->right = curr;
                    curr = curr->left;
                }
                else {

                    pred->right = NULL;

                  
                    if (!pred->left)
                        leaf.push_back(pred->val);

                    curr = curr->right;
                }
            }
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> leaf1, leaf2;

        morris(root1, leaf1);
        morris(root2, leaf2);

        return leaf1 == leaf2;
    }
};