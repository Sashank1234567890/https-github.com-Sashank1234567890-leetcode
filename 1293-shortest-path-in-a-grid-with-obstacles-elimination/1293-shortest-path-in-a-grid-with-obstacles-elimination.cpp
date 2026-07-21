class Solution
{
    public:
        int shortestPath(vector<vector < int>> &grid, int k)
        {

            int m = grid.size();
            int n = grid[0].size();

            queue<vector < int>> q;
            vector<vector<vector< int>>> vis(                m,
                vector<vector < int>> (n, vector<int> (k + 1, 0))
           );

            q.push({ 0,
                0,
                k });
            vis[0][0][k] = 1;

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
                    int rem = cur[2];

                    if (r == m - 1 && c == n - 1)
                        return steps;

                    for (int i = 0; i < 4; i++)
                    {

                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                            continue;

                        if (grid[nr][nc] == 0)
                        {

                            if (!vis[nr][nc][rem])
                            {
                                vis[nr][nc][rem] = 1;
                                q.push({ nr,
                                    nc,
                                    rem });
                            }
                        }
                        else
                        {

                            if (rem > 0 && !vis[nr][nc][rem - 1])
                            {
                                vis[nr][nc][rem - 1] = 1;
                                q.push({ nr,
                                    nc,
                                    rem - 1 });
                            }
                        }
                    }
                }

                steps++;
            }

            return -1;
        }
};