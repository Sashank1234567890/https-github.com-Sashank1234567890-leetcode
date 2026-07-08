class Solution {
public:
    vector<int> mp = {0,1,1};

    int dp[201][201][201];

    int solve(int i,int j,int cost,int k,vector<vector<int>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        if(i>=n || j>=m)
            return INT_MIN;

        cost += mp[grid[i][j]];

        if(cost > k)
            return INT_MIN;

        if(i==n-1 && j==m-1)
            return grid[i][j];

        if(dp[i][j][cost]!=-1)
            return dp[i][j][cost];

        int down = solve(i+1,j,cost,k,grid);
        int right = solve(i,j+1,cost,k,grid);

        int ans = max(down,right);

        if(ans==INT_MIN)
            return dp[i][j][cost]=INT_MIN;

        return dp[i][j][cost]=grid[i][j]+ans;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {

        memset(dp,-1,sizeof(dp));

        int ans = solve(0,0,0,k,grid);

        return ans==INT_MIN ? -1 : ans;
    }
};