class Solution
{
    public:
        int shortestPath(vector<vector < int>> &grid, int k)
        {

            int m = grid.size();
            int n = grid[0].size();

            queue<vector < int>> q;
            vector<vector < int>> best(m, vector<int> (n, INT_MAX));

            q.push({ 0,
                0,
                0 });	// row, col, obstacles used
            best[0][0] = 0;

            int steps = 0;

            int dr[] = { -1,
                1,
                0,
                0
            };
            int dc[] = { 0,
                0,
                -1,
                1
            };

            while (!q.empty())
            {

                int sz = q.size();

                while (sz--)
                {

                    auto cur = q.front();
                    q.pop();

                    int r = cur[0];
                    int c = cur[1];
                    int used = cur[2];

                    if (r == m - 1 && c == n - 1)
                        return steps;

                    for (int i = 0; i < 4; i++)
                    {

                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                            continue;

                        int nused = used + grid[nr][nc];

                        if (nused > k)
                            continue;

                        if (nused >= best[nr][nc])
                            continue;

                        best[nr][nc] = nused;
                        q.push({ nr,
                            nc,
                            nused });
                    }
                }

                steps++;
            }

            return -1;
        }
};