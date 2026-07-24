class Solution
{
    public:
        int n;
    queue<pair<int, int>> q;
    vector<vector < int>> vis;
    int dr[4] = { -1,
        1,
        0,
        0
    };
    int dc[4] = { 0,
        0,
        -1,
        1
    };

    void dfs(int r, int c, vector<vector < int>> &grid)
    {
        vis[r][c] = 1;
        q.push({ r,
            c });

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                continue;

            if (vis[nr][nc] || grid[nr][nc] == 0)
                continue;

            dfs(nr, nc, grid);
        }
    }

    int shortestBridge(vector<vector < int>> &grid)
    {
        n = grid.size();
        vis.assign(n, vector<int> (n, 0));

        bool found = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        int flips = 0;

        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                auto[r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                        continue;

                    if (vis[nr][nc])
                        continue;

                    if (grid[nr][nc] == 1)
                        return flips;

                    vis[nr][nc] = 1;
                    q.push({ nr,
                        nc });
                }
            }

            flips++;
        }

        return -1;
    }
};