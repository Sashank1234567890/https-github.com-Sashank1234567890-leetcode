class Solution
{
    public:
        vector<vector < int>> shiftGrid(vector<vector < int>> &grid, int k)
        {
            int n = grid[0].size();
            int m = grid.size();
            vector<vector < int>> ans(m, vector<int> (n, 0));
            for (int i = 0; i < m * n; i++)
            {
                int j = (i + k) % (m *n);
                int x = j / n;
                int y = j % n;
                ans[x][y] = grid[i / n][i % n];
            }
            return ans;
        }
};