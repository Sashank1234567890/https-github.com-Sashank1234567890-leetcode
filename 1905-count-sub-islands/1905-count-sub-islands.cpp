class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int m = grid1.size();
        int n = grid1[0].size();

        parent.resize(m * n);
        rank.assign(m * n, 0);

        for (int i = 0; i < m * n; i++)
            parent[i] = i;

        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

        // Build components of grid2
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid2[i][j] == 0)
                    continue;

                int id = i * n + j;

                for (auto d : dir) {

                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                        grid2[ni][nj] == 1) {

                        Union(id, ni * n + nj);
                    }
                }
            }
        }

        unordered_map<int, bool> ok;

        // Assume every island is valid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid2[i][j] == 1)
                    ok[find(i * n + j)] = true;
            }
        }

        // Invalidate islands having any cell over water in grid1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid2[i][j] == 1 && grid1[i][j] == 0)
                    ok[find(i * n + j)] = false;
            }
        }

        int ans = 0;

        for (auto it : ok) {
            if (it.second)
                ans++;
        }

        return ans;
    }
};