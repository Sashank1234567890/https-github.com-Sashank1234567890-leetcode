class Solution
{
    public:
        int countPath(vector<string> &grid, int i, int j)
        {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
                grid[i][j] == '#')
            {
                return 0;
            }
            if (i == grid.size() - 1 && j == grid[0].size() - 1 && grid[i][j] == '.') return 1;
            int left = countPath(grid, i, j + 1);
            int down = countPath(grid, i + 1, j);
            return left + down;
        }
    vector<string> createGrid(int m, int n, int k)
    {
        vector<string> grid(m, string(n, '.'));
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (countPath(grid, 0, 0) > k)
                {
                    grid[row][col] = '#';
                    if (countPath(grid, 0, 0) < k)
                        grid[row][col] = '.';
                }
                if (countPath(grid, 0, 0) == k)
                    return grid;
            }
        }
        vector<string> em;
        return em;
    }
};