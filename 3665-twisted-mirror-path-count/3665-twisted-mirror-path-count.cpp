class Solution {
public:
    int mod=1e9+7;

    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<array<int,2>>dp(n+1,{0,0});

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1){
                    dp[j][0]=1;
                    dp[j][1]=1;
                    continue;
                }

                int down=dp[j][1];
                int right=dp[j+1][0];

                if(grid[i][j]==0){
                    dp[j][0]=(down+right)%mod;
                    dp[j][1]=(down+right)%mod;
                }else{
                    dp[j][0]=down;
                    dp[j][1]=right;
                }
            }
        }

        return dp[0][0];
    }
};