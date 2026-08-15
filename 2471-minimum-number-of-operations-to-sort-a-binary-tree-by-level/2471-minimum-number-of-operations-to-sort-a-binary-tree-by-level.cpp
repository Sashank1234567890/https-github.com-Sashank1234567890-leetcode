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
    int solve(vector<int>& v) {
        int cnt = 0;

        for(int i = 0; i < v.size(); i++) {
            int mini = i;

            for(int j = i + 1; j < v.size(); j++) {
                if(v[j] < v[mini])
                    mini = j;
            }

            if(mini != i) {
                swap(v[i], v[mini]);
                cnt++;
            }
        }

        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        if(!root)
            return 0;

        int ans = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int n = q.size();
            vector<int> v;

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                v.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            ans += solve(v);
        }

        return ans;
    }
};