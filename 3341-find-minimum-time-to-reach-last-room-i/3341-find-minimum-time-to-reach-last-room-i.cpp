class Solution {
public:
    int n, m;
    vector<vector<int>> dist;
    int ans = INT_MAX;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int i, int j, int time, vector<vector<int>>& moveTime) {

        if (time >= dist[i][j])
            return;

        dist[i][j] = time;

        if (i == n - 1 && j == m - 1) {
            ans = min(ans, time);
            return;
        }

        for (int k = 0; k < 4; k++) {

            int x = i + dx[k];
            int y = j + dy[k];

            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;

            int newTime = max(time, moveTime[x][y]) + 1;

            dfs(x, y, newTime, moveTime);
        }
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {

        n = moveTime.size();
        m = moveTime[0].size();

        dist.assign(n, vector<int>(m, INT_MAX));

        dfs(0, 0, 0, moveTime);

        return ans;
    }
};