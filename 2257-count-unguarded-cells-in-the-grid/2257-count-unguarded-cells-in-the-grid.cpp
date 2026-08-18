class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        vector<vector<int>> grid(m, vector<int>(n, 0));

        // 0 = empty
        // 1 = guarded
        // 2 = guard
        // 3 = wall

        for(auto &g : guards)
            grid[g[0]][g[1]] = 2;

        for(auto &w : walls)
            grid[w[0]][w[1]] = 3;

        // Left -> Right
        for(int i = 0; i < m; i++) {
            bool seen = false;

            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    seen = true;
                else if(grid[i][j] == 3)
                    seen = false;
                else if(seen)
                    grid[i][j] = 1;
            }
        }

        // Right -> Left
        for(int i = 0; i < m; i++) {
            bool seen = false;

            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 2)
                    seen = true;
                else if(grid[i][j] == 3)
                    seen = false;
                else if(seen)
                    grid[i][j] = 1;
            }
        }

        // Top -> Bottom
        for(int j = 0; j < n; j++) {
            bool seen = false;

            for(int i = 0; i < m; i++) {
                if(grid[i][j] == 2)
                    seen = true;
                else if(grid[i][j] == 3)
                    seen = false;
                else if(seen)
                    grid[i][j] = 1;
            }
        }

        // Bottom -> Top
        for(int j = 0; j < n; j++) {
            bool seen = false;

            for(int i = m - 1; i >= 0; i--) {
                if(grid[i][j] == 2)
                    seen = true;
                else if(grid[i][j] == 3)
                    seen = false;
                else if(seen)
                    grid[i][j] = 1;
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    ans++;
            }
        }

        return ans;
    }
};