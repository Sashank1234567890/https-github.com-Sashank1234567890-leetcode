class Solution {
public:
    void check(TreeNode* root, unordered_map<int, int>& mp,
               int odd, int& cnt) {

        if(!root)
            return;

        mp[root->val]++;

        if(mp[root->val] & 1)
            odd++;
        else
            odd--;

        if(!root->left && !root->right) {
            if(odd <= 1)
                cnt++;
        }
        else {
            check(root->left, mp, odd, cnt);
            check(root->right, mp, odd, cnt);
        }

        mp[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> mp;
        int cnt = 0;

        check(root, mp, 0, cnt);

        return cnt;
    }
};