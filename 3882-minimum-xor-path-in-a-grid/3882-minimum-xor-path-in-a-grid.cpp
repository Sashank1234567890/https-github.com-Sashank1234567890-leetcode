class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        queue<tuple<int,int,int>> q;

        dp[0][0][grid[0][0]] = 1;
        q.push({0, 0, grid[0][0]});

        int dx[] = {1, 0};
        int dy[] = {0, 1};

        while(!q.empty()) {
            auto [i, j, xorVal] = q.front();
            q.pop();

            for(int k = 0; k < 2; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(x >= m || y >= n)
                    continue;

                int newXor = xorVal ^ grid[x][y];

                if(!dp[x][y][newXor]) {
                    dp[x][y][newXor] = 1;
                    q.push({x, y, newXor});
                }
            }
        }

        for(int xorVal = 0; xorVal < 1024; xorVal++) {
            if(dp[m-1][n-1][xorVal])
                return xorVal;
        }

        return -1;
    }
};