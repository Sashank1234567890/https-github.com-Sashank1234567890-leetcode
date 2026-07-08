class Solution
{
    public:
        int maxPathScore(vector<vector < int>> &grid, int k)
        {
            int n = grid.size();
            int m = grid[0].size();

            vector<vector<vector< int>>> t(n + 1,
                vector<vector < int>> (m + 1, vector<int> (k + 1, INT_MIN))
           );

            for (int cost = 0; cost + (grid[n - 1][m - 1] > 0) <= k; cost++)
            {
                t[n - 1][m - 1][cost] = grid[n - 1][m - 1];
            }

            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = m - 1; j >= 0; j--)
                {
                    if (i == n - 1 && j == m - 1)
                        continue;

                    for (int cost = k; cost >= 0; cost--)
                    {
                        int newCost = cost + (grid[i][j] > 0);

                        if (newCost > k)
                            continue;

                        int down = INT_MIN;
                        int right = INT_MIN;

                        
                            down = t[i + 1][j][newCost];

                        
                            right = t[i][j + 1][newCost];

                        int bestNext = max(down, right);

                        if (bestNext == INT_MIN)
                            t[i][j][cost] = INT_MIN;
                        else
                            t[i][j][cost] = grid[i][j] + bestNext;
                    }
                }
            }

            return t[0][0][0] == INT_MIN ? -1 : t[0][0][0];
        }
};