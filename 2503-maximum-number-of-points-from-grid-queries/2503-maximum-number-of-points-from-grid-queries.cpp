class Solution
{
public:
    vector<vector<int>> directions = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries)
    {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);

        vector<pair<int,int>> sortedQ;

        for(int i = 0; i < Q; i++)
            sortedQ.push_back({queries[i], i});

        sort(sortedQ.begin(), sortedQ.end());

        auto lambda = [&](pair<int,int>& a, pair<int,int>& b) {
            return grid[a.first][a.second] > grid[b.first][b.second];
        };

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            decltype(lambda)
        > pq(lambda);

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pq.push({0, 0});
        visited[0][0] = true;

        int points = 0;

        for(auto q : sortedQ)
        {
            int queryValue = q.first;
            int idx = q.second;

            while(!pq.empty() &&
                  grid[pq.top().first][pq.top().second] < queryValue)
            {
                int i = pq.top().first;
                int j = pq.top().second;

                pq.pop();

                points++;

                for(auto dir : directions)
                {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if(ni >= 0 && ni < m &&
                       nj >= 0 && nj < n &&
                       !visited[ni][nj])
                    {
                        pq.push({ni, nj});
                        visited[ni][nj] = true;
                    }
                }
            }

            result[idx] = points;
        }

        return result;
    }
};