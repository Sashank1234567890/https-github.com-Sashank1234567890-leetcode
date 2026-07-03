class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[m-1][n-1] = 0;

        int maxVal = 0;
        for(auto &row : grid) {
            for(int &val : row) {
                maxVal = max(maxVal, val);
            }
        }

        vector<int> teleportCost(maxVal+1, INT_MAX);

        for(int t = 0; t <= k; t++) {//rolling dp

            for(int i = m-1; i >= 0; i--) {
                for(int j = n-1; j >= 0; j--) {

                    if(i+1 < m)
                        dp[i][j] = min(dp[i][j], grid[i+1][j] + dp[i+1][j]);
                    
                    if(j+1 < n)
                        dp[i][j] = min(dp[i][j], grid[i][j+1] + dp[i][j+1]);

                    if(t > 0) {
                        dp[i][j] = min(dp[i][j], teleportCost[grid[i][j]]);
                    }
                }
            }

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    teleportCost[grid[i][j]] = min(teleportCost[grid[i][j]], dp[i][j]);
                }
            }

            for(int i = 1; i < teleportCost.size(); i++) {
                teleportCost[i] = min(teleportCost[i], teleportCost[i-1]);
            }
        }

        return dp[0][0];
    }
};