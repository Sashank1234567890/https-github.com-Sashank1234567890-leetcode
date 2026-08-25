class Solution {
public:
    TreeNode* solve(vector<int>& arr, int l, int r) {
        if(l > r)
            return NULL;

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = solve(arr, l, mid - 1);
        root->right = solve(arr, mid + 1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;

        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }

        return solve(arr, 0, arr.size() - 1);
    }
};