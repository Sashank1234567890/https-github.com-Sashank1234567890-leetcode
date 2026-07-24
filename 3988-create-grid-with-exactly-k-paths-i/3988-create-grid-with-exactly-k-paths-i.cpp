class Solution
{
    public:
        vector<vector < int>> dp;

    int countPath(vector<string> &grid, int i, int j)
    {

        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#')
            return 0;

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] =
            countPath(grid, i + 1, j) +
            countPath(grid, i, j + 1);
    }

    vector<string> createGrid(int m, int n, int k)
    {

        vector<string> grid(m, string(n, '.'));

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {

                dp.assign(m, vector<int> (n, -1));
                int paths = countPath(grid, 0, 0);

                if (paths > k)
                {

                    grid[row][col] = '#';

                    dp.assign(m, vector<int> (n, -1));

                    if (countPath(grid, 0, 0) < k)
                        grid[row][col] = '.';
                }

                dp.assign(m, vector<int> (n, -1));

                if (countPath(grid, 0, 0) == k)
                    return grid;
            }
        }

        return {};
    }
};