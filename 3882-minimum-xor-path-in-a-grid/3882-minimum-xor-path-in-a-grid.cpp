class Solution {
public:
    bitset<1024> solve(vector<vector<int>>& grid, int i, int j,
                       vector<vector<bitset<1024>>>& dp,
                       vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0)
            return bitset<1024>(0);

        if(i == 0 && j == 0) {
            bitset<1024> ans;
            ans[grid[0][0]] = 1;
            return ans;
        }

        if(vis[i][j])
            return dp[i][j];

        bitset<1024> up = solve(grid, i-1, j, dp, vis);
        bitset<1024> left = solve(grid, i, j-1, dp, vis);

        bitset<1024> combined = up | left;

        for(int xorVal = 0; xorVal < 1024; xorVal++) {
            if(combined[xorVal]) {
                int resultXorVal = xorVal ^ grid[i][j];
                dp[i][j][resultXorVal] = 1;
            }
        }

        vis[i][j] = 1;
        return dp[i][j];
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        bitset<1024> ans = solve(grid, m-1, n-1, dp, vis);

        for(int xorVal = 0; xorVal < 1024; xorVal++) {
            if(ans[xorVal])
                return xorVal;
        }

        return -1;
    }
};