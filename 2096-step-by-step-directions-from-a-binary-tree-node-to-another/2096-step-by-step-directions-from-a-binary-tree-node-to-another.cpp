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

    bool findPath(TreeNode* root, int target, string &path) {
        if (!root)
            return false;

        if (root->val == target)
            return true;

        path.push_back('L');

        if (findPath(root->left, target, path))
            return true;

        path.pop_back();

        path.push_back('R');

        if (findPath(root->right, target, path))
            return true;

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);

        string startPath = "";
        string destPath = "";

        findPath(lca, startValue, startPath);
        findPath(lca, destValue, destPath);

        string ans(startPath.size(), 'U');
        ans += destPath;

        return ans;
    }
};