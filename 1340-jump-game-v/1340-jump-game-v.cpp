class Solution {
public:

    int jump(int idx, vector<int>& arr, int d,vector<int>&dp) {

        int n = arr.size();

        int ans = 1;

        if(dp[idx]!=INT_MIN)
           return dp[idx];
        // right
        for(int j = idx + 1; j <= min(n - 1, idx + d); j++) {

            if(arr[j] >= arr[idx])
                break;

            ans = max(ans, 1 + jump(j, arr, d,dp));
        }

        // left
        for(int j = idx - 1; j >= max(0, idx - d); j--) {

            if(arr[j] >= arr[idx])
                break;

            ans = max(ans, 1 + jump(j, arr, d,dp));
        }

        return dp[idx]= ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        int ans = 1;
        vector<int>dp(n,INT_MIN);
        for(int i = 0; i < n; i++) {
            ans = max(ans, jump(i, arr, d,dp));
        }

        return ans;
    }
};