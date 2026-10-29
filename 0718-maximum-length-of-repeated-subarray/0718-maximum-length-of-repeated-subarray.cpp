class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp, int& ans) {
        if(i==0 || j==0)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(nums1[i-1]==nums2[j-1]){
            dp[i][j]=1+solve(nums1,nums2,i-1,j-1,dp,ans);
            ans=max(ans,dp[i][j]);
        }else{
            dp[i][j]=0;
        }

        return dp[i][j];
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                solve(nums1,nums2,i,j,dp,ans);
            }
        }

        return ans;
    }
};