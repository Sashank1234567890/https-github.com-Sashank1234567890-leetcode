class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : roads) {
            Union(e[0], e[1]);
        }

        int root = find(1);

        int ans = INT_MAX;

        for (auto &e : roads) {

            if (find(e[0]) == root) {
                ans = min(ans, e[2]);
            }
        }

        return ans;
    }
};