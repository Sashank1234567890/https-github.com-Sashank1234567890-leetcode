class Solution {
public:

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //down, up, right , left

    //BFS
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid1.size();
        int n = grid1[0].size();

        bool result = true;

        queue<pair<int, int>> que; //{i, j} //BFS me we use queue
        que.push({i, j});
        grid2[i][j] = -1; //mark visited

        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            if(grid1[x][y] != 1) { //grid1 must have 1 at that same co-ordinate
                result = false;
            }

            for(vector<int>& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1) {
                    grid2[newX][newY] = -1; //mark visited
                    que.push({newX, newY});
                }
            }
        }

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //DFS
        int subIslands = 0;
        int m = grid2.size(); //rows
        int n = grid2[0].size(); //cols

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) { //Found an island
                    subIslands++;
                }
            }
        }

        return subIslands;
    }
};
