class Solution
{
    public:

        int longestCycle = 0;

    void dfs(int node,vector<int> &favorite,vector<bool> &visited,vector<int> &depth,int d,int &happyCouple,unordered_map<int, vector < int>> &adj)
    {
        visited[node] = true;
        depth[node] = d;

        int next = favorite[node];

        if (!visited[next])
        {

            dfs(next, favorite, visited, depth, d + 1,happyCouple, adj);
        }
        else if (depth[next] != -1)
        {

            int cycleLength = d - depth[next] + 1;

            longestCycle = max(longestCycle, cycleLength);

            if (cycleLength == 2)
            {

                vector<bool> vis(favorite.size(), false);

                vis[node] = true;
                vis[next] = true;

                happyCouple += 2 +BFS(node, adj, vis) +BFS(next, adj, vis);
            }
        }

        depth[node] = -1;	
    }

    int BFS(int start,
        unordered_map<int, vector < int>> &adj,
        vector<bool> &visited)
    {
        queue<pair<int, int>> q;

        q.push({ start,
            0 });

        int mx = 0;

        while (!q.empty())
        {

            auto[node, dist] = q.front();
            q.pop();

            for (auto child: adj[node])
            {

                if (!visited[child])
                {

                    visited[child] = true;

                    q.push({ child, dist + 1 });

                    mx = max(mx, dist + 1);
                }
            }
        }

        return mx;
    }

    int maximumInvitations(vector<int> &favorite)
    {

        int n = favorite.size();

        unordered_map<int, vector < int>> adj;

        for (int i = 0; i < n; i++)
            adj[favorite[i]].push_back(i);

        vector<bool> visited(n, false);
        vector<int> depth(n, -1);

        int happyCouple = 0;

        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {

                dfs(i, favorite, visited, depth, 0, happyCouple, adj);
            }
        }

        return max(longestCycle, happyCouple);
    }
};