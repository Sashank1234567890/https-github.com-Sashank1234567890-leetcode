class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        
            int n = grid.size(), m = grid[0].size();

            queue<pair<int, int>>q;
           
            vector<pair<int, int>> dir = {
		{ 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 }
            };
            auto isValid =[&](int x, int y)
            {
                return !(x < 0 || y < 0 || y >= m || x >= n || grid[x][y] == 0);
            };
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {  
                    if (grid[i][j] != 0){
                     int sum=0;
                    q.push({i,j});
                 
                    
                        while (!q.empty())
                        {
                            auto [i, j] = q.front();
                            q.pop();
                           
                             if(!isValid(i,j))
                              continue;
                                  sum=(sum+grid[i][j])%k;
                            grid[i][j] = 0;
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
                    if(!sum)
                    ans++;
                    }
                 
                }
            }
   return ans; }
};