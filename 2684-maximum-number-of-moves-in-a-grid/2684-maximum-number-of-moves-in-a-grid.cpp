class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>>& grid) {

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        int dr[] = {-1, 0, 1};

        for (int k = 0; k < 3; k++) {

            int ni = i + dr[k];
            int nj = j + 1;

            if (ni >= 0 && ni < n && nj < m &&
                grid[ni][nj] > grid[i][j]) {

                ans = max(ans, 1 + dfs(ni, nj, grid));
            }
        }

        return dp[i][j] = ans;
    }

    int maxMoves(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, 0, grid));
        }

        return ans;
    }
};