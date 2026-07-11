class UnionFind
{
    public:
        vector<int> parent, rank;

    UnionFind(int n)
    {
        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution
{
    public:
        int countCompleteComponents(int n, vector<vector < int>> &edges)
        {
            vector<vector < int>> components(n);
            vector<int> degree(n, 0);

            UnionFind uf(n);

            for (auto &edge: edges)
            {
                int u = edge[0];
                int v = edge[1];

                degree[u]++;
                degree[v]++;

                uf.Union(u, v);
            }

            for (int i = 0; i < n; i++)
            {
                uf.find(i);
                components[uf.parent[i]].push_back(i);
            }

            int cnt = 0;

            for (int i = 0; i < n; i++)
            {
                if (components[i].empty())
                    continue;

                int sz = components[i].size();
                bool complete = true;

                for (int node: components[i])
                {
                    if (degree[node] != sz - 1)
                    {
                        complete = false;
                        break;
                    }
                }

                if (complete)
                    cnt++;
            }

            return cnt;
        }
};