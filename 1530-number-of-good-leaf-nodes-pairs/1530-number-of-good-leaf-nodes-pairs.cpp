class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root, int distance, vector<int>& v) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            v.push_back(0);
            return;
        }

        vector<int> left, right;

        solve(root->left, distance, left);
        solve(root->right, distance, right);

        for (int x : left) {
            for (int y : right) {
                if (x + y + 2 <= distance)
                    ans++;
            }
        }

        for (int x : left) {
            if (x + 1 < distance)
                v.push_back(x + 1);
        }

        for (int y : right) {
            if (y + 1 < distance)
                v.push_back(y + 1);
        }
    }

    int countPairs(TreeNode* root, int distance) {
        ans = 0;

        vector<int> v;
        solve(root, distance, v);

        return ans;
    }
};