class Solution {
public:
    typedef tuple<int, int, int> t;

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        health -= grid[0][0];
        if (health <= 0)
            return false;

        queue<t> q;
        vector<vector<int>> best(n, vector<int>(m, -1));

        q.push({0, 0, health});
        best[0][0] = health;

        while (!q.empty()) {
            auto [i, j, h] = q.front();
            q.pop();

            if (i == n - 1 && j == m - 1)
                return true;

            for (auto &d : dirs) {
                int x = i + d[0];
                int y = j + d[1];

                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;

                int nh = h - grid[x][y];

                if (nh <= 0)
                    continue;

                if (nh > best[x][y]) {
                    best[x][y] = nh;
                    q.push({x, y, nh});
                }
            }
        }

        return false;
    }
};