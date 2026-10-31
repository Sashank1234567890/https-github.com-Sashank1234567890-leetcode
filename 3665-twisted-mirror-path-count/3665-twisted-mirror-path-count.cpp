class Solution {
public:
    int mod=1e9+7;
    int path(vector<vector<int>>& grid,int i,int j,bool dir,vector<vector<vector<int>>>&dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m||j>=n)
        return 0;
        if(i==m-1&&j==n-1)
        return 1;
        if(dp[i][j][dir]!=-1)
        return dp[i][j][dir];
        int ans=0;

        if(grid[i][j]==0){
             if(i+1<m)
                 ans=(ans+path(grid,i+1,j,1,dp))%mod;
             if(j+1<n)
                 ans=(ans+path(grid,i,j+1,0,dp))%mod;
        }else{
             if(dir==1){
                ans=(ans+path(grid,i,j+1,0,dp))%mod;
             }else{
                ans=(ans+path(grid,i+1,j,1,dp))%mod;
             }

        }
       
       
        return dp[i][j][dir]=ans%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        dp[m-1][n-1][0]=1;
        dp[m-1][n-1][1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1)
                continue;
                for(int prev=1;prev>=0;prev--){
                if(grid[i][j]==0){
                    dp[i][j][prev]=(dp[i][j][prev]+dp[i+1][j][1]+dp[i][j+1][0])%mod;
                }else{
                dp[i][j][prev]=(dp[i][j][prev]+dp[i+!prev][j+prev][!prev])%mod;
                    
                }
                }
            }
        }
   return dp[0][0][0]; }
};