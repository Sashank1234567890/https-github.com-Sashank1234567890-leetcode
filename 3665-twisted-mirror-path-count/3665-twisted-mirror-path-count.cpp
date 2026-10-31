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
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(2,-1)));
        return (path(grid,0,0,0,dp))%mod;
    }
};