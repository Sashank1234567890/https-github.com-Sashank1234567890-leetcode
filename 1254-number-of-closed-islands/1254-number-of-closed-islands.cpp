class Solution
{
    public:

        int closedIsland(vector<vector < int>> &grid)
        {
            int n = grid.size(), m = grid[0].size();

            queue<pair<int, int>>q;
            for (int i = 0; i < n; i++)
            {
                if (grid[i][0] == 0)
                {
                    q.push({ i,0 });
                }
                if (grid[i][m - 1] == 0)
                {
                    q.push({ i, m - 1 });
                }
            }
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[0][j] == 0)
                {
                    q.push({ 0,j });
                }
                if (grid[n - 1][j] == 0)
                {
                    q.push({ n - 1,j });
                }
            }
            vector<pair<int, int>> dir = {
		{ 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 }
            };
            auto isValid =[&](int x, int y)
            {
                return !(x < 0 || y < 0 || y >= m || x >= n || grid[x][y] != 0);
            };
            while (!q.empty())
            {
                auto [i, j] = q.front();
                q.pop();
                if(!isValid(i,j))
                continue;
                cout<<i<<" "<<j<<endl;
                grid[i][j] = 2;
                for (auto p: dir)
                {
                    auto [x, y] = p;
                    int x_ = i + x;
                    int y_ = j + y;
                    if (isValid(x_, y_))
                    {
                        q.push({ x_,y_ });
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < m; j++)
                {
                    if (grid[i][j] == 0){
                    q.push({i,j});
                    ans++;
                    
                        while (!q.empty())
                        {
                            auto [i, j] = q.front();
                            q.pop();
                             if(!isValid(i,j))
                              continue;
                            grid[i][j] = 2;
                            for (auto p: dir)
                            {
                                auto [x, y] = p;
                                int x_ = i + x;
                                int y_ = j + y;
                                if (isValid(x_, y_))
                                {
                                    q.push({ x_,y_ });
                                }
                            }
                        }
                    }
                }
            }
       return ans; }
};