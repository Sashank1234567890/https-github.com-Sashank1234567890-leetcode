class Solution {
public:
    TreeNode* LCA(TreeNode* root, int s, int t) {
        if (!root)
            return NULL;

        if (root->val == s || root->val == t)
            return root;

        TreeNode* left = LCA(root->left, s, t);
        TreeNode* right = LCA(root->right, s, t);

        if (left && right)
            return root;

        if (left)
            return left;

        return right;
    }

    void findPath(TreeNode* root, int target, string &path, bool &found) {
        if (!root || found)
            return;

        if (root->val == target) {
            found = true;
            return;
        }

        path.push_back('L');
        findPath(root->left, target, path, found);

        if (found)
            return;

        path.pop_back();

        path.push_back('R');
        findPath(root->right, target, path, found);

        if (found)
            return;

        path.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);

        string startPath = "";
        string destPath = "";

        bool found = false;
        findPath(lca, startValue, startPath, found);

        found = false;
        findPath(lca, destValue, destPath, found);

        string ans(startPath.size(), 'U');
        ans += destPath;

        return ans;
    }
};