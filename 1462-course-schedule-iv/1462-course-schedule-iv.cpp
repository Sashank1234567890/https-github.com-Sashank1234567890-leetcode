class Solution
{
    public:
        vector<bool> checkIfPrerequisite(int n, vector<vector < int>> &prerequisites, vector< vector< int>> &queries)
        {

            vector<vector < int>> adj(n);
            vector<int> indegree(n, 0);

            for (auto &e: prerequisites)
            {
                adj[e[0]].push_back(e[1]);
                indegree[e[1]]++;
            }

            queue<int> q;

            for (int i = 0; i < n; i++)
            {
                if (indegree[i] == 0)
                    q.push(i);
            }

            vector<unordered_set < int>> pre(n);

            while (!q.empty())
            {

                int u = q.front();
                q.pop();

                for (int v: adj[u])
                {

                    pre[v].insert(u);
                    pre[v].insert(pre[u].begin(), pre[u].end());

                    indegree[v]--;

                    if (indegree[v] == 0)
                        q.push(v);
                }
            }

            vector<bool> ans;

            for (auto &q: queries)
                ans.push_back(pre[q[1]].count(q[0]));

            return ans;
        }
};