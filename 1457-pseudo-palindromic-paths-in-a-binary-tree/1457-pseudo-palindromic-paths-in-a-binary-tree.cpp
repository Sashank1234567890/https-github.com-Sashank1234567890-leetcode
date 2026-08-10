/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void check(TreeNode *root, unordered_map<int, int> &mp, int odd, int &cnt)
        {
            if (!root)
            {
                return;
            }
            if (!root->left && !root->right)
            {
                mp[root->val]++;
                if (mp[root->val] % 2)
                {
                    odd++;
                }
                else
                {
                    odd--;
                }
                if (odd <= 1)
                    cnt++;
                mp[root->val]--;
                return;
            }
            mp[root->val]++;
            if (mp[root->val] % 2)
            {
                odd++;
            }
            else
            {
                odd--;
            }

            check(root->left, mp, odd, cnt);
            check(root->right, mp, odd, cnt);
            mp[root->val]--;
        }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        unordered_map<int, int> mp;
        int cnt = 0;
        check(root, mp, 0, cnt);
        return cnt;
    }
};