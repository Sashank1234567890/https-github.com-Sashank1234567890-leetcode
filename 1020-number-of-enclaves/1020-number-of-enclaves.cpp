class Solution {
public:
    int m, n;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& grid, int i, int j) {

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;

        grid[i][j] = 0;

        for (int k = 0; k < 4; k++)
            dfs(grid, i + dx[k], j + dy[k]);
    }

    int numEnclaves(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

     
        for (int j = 0; j < n; j++) {

            if (grid[0][j] == 1)
                dfs(grid, 0, j);

            if (grid[m - 1][j] == 1)
                dfs(grid, m - 1, j);
        }

     
        for (int i = 0; i < m; i++) {

            if (grid[i][0] == 1)
                dfs(grid, i, 0);

            if (grid[i][n - 1] == 1)
                dfs(grid, i, n - 1);
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};