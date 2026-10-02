class Solution {
public:
    bool is(vector<vector<char>>& grid,int i,int j,int open, vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1&&j==m-1){
            return (grid[i][j]==')') && (open==1);
        }
        if(i>=n||j>=m)
        return false;
        if(grid[i][j]==')'&&open==0){
              return false;
        }
        if(dp[i][j][open]!=-1)
        return dp[i][j][open];
        int newopen=open+(grid[i][j]=='('?1:-1);
        bool down=is(grid,i+1,j,newopen,dp);
        bool left=is(grid,i,j+1,newopen,dp);
        return dp[i][j][open]=left||down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if((n-1==0&&m-1==0)||grid[0][0]!='('||grid[n-1][m-1]!=')')
        return false;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(n+m,-1)));
        return is(grid,0,0,0,dp);
    }
};