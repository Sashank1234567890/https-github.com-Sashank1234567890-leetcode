class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp, int& ans) {
        if(i<0 || j<0)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int len=0;

        if(nums1[i]==nums2[j]){
            len=1+solve(nums1,nums2,i-1,j-1,dp,ans);
            ans=max(ans,len);
        }

        solve(nums1,nums2,i-1,j,dp,ans);
        solve(nums1,nums2,i,j-1,dp,ans);

        return dp[i][j]=len;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=0;

        solve(nums1,nums2,n-1,m-1,dp,ans);

        return ans;
    }
};